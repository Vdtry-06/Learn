package Socket.UDP;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.time.LocalDateTime;

public class UDPServer {
    private static final int PORT = 9999;
    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) {
        DatagramSocket socket = null;

        try {
            // 1. Tạo đối tượng DatagramSocket với số cổng xác định
            socket = new DatagramSocket(PORT);
            System.out.println("UDP Server started on port " + PORT);
            System.out.println("Waiting for UDP connection...");

            while (true) {
                // 2. Khai báo bộ đệm nhập/xuất hay inBuffer/outBuffer dạng mảng kiểu byte
                byte[] inBuffer = new byte[BUFFER_SIZE];
                byte[] outBuffer;

                // 3. Khai báo đối tượng DatagramPackage để gửi/nhận
                DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);

                // 4. Thực hiện gửi/nhận gói tin với phương thức send() / receive()
                socket.receive(inPacket);

                // Xử lý dữ liệu nhận được
                String clientMessage = new String(inPacket.getData(), 0, inPacket.getLength());
                String clientIP = inPacket.getAddress().getHostAddress();
                int clientPort = inPacket.getPort();

                System.out.println("Client received [" + clientIP + ":" + clientPort + "]: " + clientMessage);


                // Kiểm tra lệnh thoát
                if (clientMessage.equals("exit")) {
                    System.out.println("UDP Server stopped");
                    break;
                }

                // Chuẩn bị phản hồi
                String response = "Server received: " + clientMessage + " (Time: " + LocalDateTime.now() + ")";
                outBuffer = response.getBytes();

                // Tạo DatagramPacket để gửi phản hồi
                DatagramPacket outPacket = new DatagramPacket(
                        outBuffer,
                        outBuffer.length,
                        inPacket.getAddress(),
                        inPacket.getPort()
                );

                // Gửi phản hồi client
                socket.send(outPacket);
                System.out.println("Response sent to client");

            }

        } catch (SocketException e) {
            System.err.println("Error Socket: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("I/O Exception: " + e.getMessage());
        } finally {
            // Bước 5: Đóng socket và giải phóng tài nguyên
            if (socket != null && !socket.isClosed()) {
                socket.close();
                System.out.println("Server closed");
            }
        }
    }
}

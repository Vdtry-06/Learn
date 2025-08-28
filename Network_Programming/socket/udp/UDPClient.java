package socket.udp;

import java.io.IOException;
import java.net.*;
import java.util.Scanner;

public class UDPClient {
    private static final String SERVER_HOST = "127.0.0.1";
    private static final int SERVER_PORT = 9999;
    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) {
        DatagramSocket socket = null;
        Scanner userInput = new Scanner(System.in);

        try {
            // 1. Tạo đối tượng DatagramSocket với số cổng nào đó hoặc xác định
            socket = new DatagramSocket();
            System.out.println("UDP client started");
            System.out.println("Connecting to " + SERVER_HOST + ":" + SERVER_PORT);

            InetAddress serverAddress = InetAddress.getByName(SERVER_HOST);

            while (true) {
                // 2. Khai báo bộ đệm xuất/nhập hay outBuffer/inBuffer dạng mảng kiểu byte
                byte[] inBuffer = new byte[BUFFER_SIZE];
                byte[] outBuffer;

                // Nhận tin nhắn từ User
                System.out.print("Client: ");
                String message = userInput.nextLine();

                // Chuyển message thành mảng byte
                outBuffer = message.getBytes();

                // 3. Khai báo đối tượng DatagramPackage để gửi/nhận
                DatagramPacket outPacket = new DatagramPacket(
                        outBuffer,
                        outBuffer.length,
                        serverAddress,
                        SERVER_PORT
                );

                // 4. Thực hiện gửi/nhận gói tin với phương thức send() / receive()
                socket.send(outPacket);
                System.out.println("Message sent");

                // Kiểm tra lệnh thoát
                if (message.equals("exit")) {
                    break;
                }

                // Nhận phản hồi từ server
                DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
                socket.receive(inPacket);

                String serverResponse = new String(inPacket.getData(), 0, inPacket.getLength());
                System.out.println("Server Response: " + serverResponse);
            }

        }  catch (SocketException e) {
            System.err.println("Error Socket: " + e.getMessage());
        } catch (UnknownHostException e) {
            System.err.println("Host not found: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("I/O Exception: " + e.getMessage());
        } finally {
            // Bước 5: Đóng socket và giải phóng tài nguyên
            if (socket != null && !socket.isClosed()) {
                socket.close();
                System.out.println("Client closed");
            }
            userInput.close();
        }
    }
}

package Socket.TCP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.time.LocalDateTime;

public class TCPServer {
    private static final int PORT = 8888;
    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        try {
            // Bước 1: Tạo đối tượng ServerSocket với một số hiệu cổng xác định
            serverSocket = new ServerSocket(PORT);
            System.out.println("Server started on port " + PORT);
            System.out.println("Waiting for connection...");

            while(true) {
                // Bước 2: Đặt ServerSocket ở trạng thái nghe và chờ kết nối
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected " + clientSocket.getInetAddress());

                // Bước 3: Khai báo luồng nhập/xuất cho Socket
                BufferedReader input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter output = new PrintWriter(clientSocket.getOutputStream(), true);

                // Bước 4: Thực hiện truyền dữ liệu với client
                String clientMessage;
                while((clientMessage = input.readLine()) != null) {
                    System.out.println("Client received: " + clientMessage);

                    // Kiểm tra lệnh thoát
                    if (clientMessage.equals("bye")) {
                        break;
                    }

                    // Echo message với thời gian
                    String response = "Server received: " + clientMessage + " (Time: " + LocalDateTime.now() + ")";
                    output.println(response);
                }

                // Bước 5: Đóng kết nối với client hiện tại
                input.close();
                output.close();
                clientSocket.close();
                System.out.println("Client " + clientSocket.getInetAddress() + " disconnected");

                // Bước 6: Trở về bước 2 - chờ kết nối tiếp theo
                System.out.println("Waiting for connection...");
            }

        } catch (IOException e) {
            System.err.println("Error Server: " + e.getMessage());
        } finally {
            try {
                if (serverSocket != null && !serverSocket.isClosed()) {
                    serverSocket.close();
                }
            } catch (IOException e) {
                System.err.println("Error Server: " + e.getMessage());
            }
        }
    }
}

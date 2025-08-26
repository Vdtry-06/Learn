package Socket.TCP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class TCPClient {
    private static final String SERVER_HOST = "127.0.0.1";
    private static final int SERVER_PORT = 8888;

    public static void main(String[] args) {
        Socket socket = null;
        Scanner userInput = new Scanner(System.in);

        try {
            // Bước 1: Tạo Socket và thiết lập kết nối tới server
            socket = new Socket(SERVER_HOST, SERVER_PORT);
            System.out.println("Connected to " + SERVER_HOST + ":" + SERVER_PORT);

            // Bước 2: Khai báo luồng nhập/xuất cho Socket
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);

            // Bước 3: Thực hiện truyền dữ liệu qua mạng
            System.out.println("Enter message 'bye' to exit");

            String userMessage;
            while(true) {
                System.out.print("Client: ");
                userMessage = userInput.nextLine();

                // Gửi tin nhắn tới server
                output.println(userMessage);

                // Nhận phản hồi từ server
                String serverResponse = input.readLine();
                if (serverResponse != null) {
                    System.out.println("Server response received: " + serverResponse);
                }

                // Kiểm tra lệnh thoát
                if (userMessage.equals("bye")) {
                    break;
                }
            }

            // Bước 4: Đóng Socket và giải phóng tài nguyên
            input.close();
            output.close();
            userInput.close();

        } catch(UnknownHostException e) {
            System.err.println("Server not found: " + e.getMessage());
        } catch(IOException e) {
            System.err.println("I/O exception: " + e.getMessage());
        }
        finally {
            try {
                if (socket != null && !socket.isClosed()) {
                    socket.close();
                    System.out.println("disconnected");
                }
            } catch(IOException e) {
                System.err.println("Error closing socket: " + e.getMessage());
            }
        }
    }
}

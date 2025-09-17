package ptit.tcp.NYP5nppe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2208;

    public static void main(String[] args) throws IOException {
        String studentCode = "B22DCCN866";
        String qCode = "NYP5nppe";

        // Bước 1: Tạo Socket và thiết lập kết nối tới server
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);

        // Bước 2: khai báo luồng nhập xuất cho Socket
        BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter output = new PrintWriter(socket.getOutputStream(), true);

        // Bước 3: Thực hiện truyền dữ liệu qua mạng
        String clientMessage = studentCode + ";" + qCode;

        // Gửi tin nhắn tới server
        output.println(clientMessage);

        // Nhận phản hồi từ server
        String serverResponse = input.readLine();

        String[] arr = serverResponse.split(", ");
        clientMessage = "";
        for (String s : arr) {
            String edu = s.substring(s.indexOf("."));
            if (edu.equals(".edu")) {
                clientMessage += s + ", ";
            }
        }
        clientMessage = clientMessage.substring(0, clientMessage.length() - 2);
        output.println(clientMessage);
        System.out.println("Client received: " + clientMessage);
        input.close();
        output.close();
    }
}

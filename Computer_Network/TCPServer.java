import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {
    public static void main(String[] args) throws Exception{
        String clientSentence; // câu khách hàng
        String capitalizedSentence; // câu viết hoa

        // Tạo socket chào mừng tại cổng 5000
        ServerSocket welcomeSocket = new ServerSocket(5000);

        while(true) {
            // Đợi đã, trên socket chào mừng để khách hàng liên hệ
            Socket connectionSocket = welcomeSocket.accept();

            // Tạo luồng đầu vào, gắn vào socket
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));

            // Tạo luồng đầu ra, gắn vào socket
            DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());

            // Đọc dòng từ Socket
            clientSentence = inFromClient.readLine();
            capitalizedSentence = clientSentence.toUpperCase() + "\n";

            // Viết dòng ra Socket
            outToClient.writeBytes(capitalizedSentence);
        }
        // Kết thúc vòng lặp while, lặp lại và chờ kết nối máy khách khác
    }
}

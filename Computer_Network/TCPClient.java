import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class TCPClient {
    public static void main(String[] args) throws Exception{
        String sentence; // câu
        String modifiedSentence; // câu sửa đổi

        // tạo luồng đầu vào
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));

        // Tạo socket client, kết nối với server
        Socket clientSocket = new Socket("127.0.0.1", 5000);

        // Tạo luồng đầu ra được gắn vào Socket
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

        // Tạo luồng đầu vào được gắn vào Socket
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        sentence = inFromUser.readLine();

        // Gửi dòng đến máy chủ
        outToServer.writeBytes(sentence + "\n");

        // Đọc dòng từ máy chủ
        modifiedSentence = inFromServer.readLine();
        System.out.println("FROM SERVER: " + modifiedSentence);
        clientSocket.close();

    }
}

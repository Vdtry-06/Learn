import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPClient {
    public static void main(String[] args) {
        try {
            BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
            DatagramSocket clientSocket = new DatagramSocket();

            // Sử dụng địa chỉ IP localhost để kết nối với server
            InetAddress IPAddress = InetAddress.getByName("127.0.0.1");

            // Mảng byte để gửi và nhận dữ liệu
            byte[] sendData = new byte[1024];
            byte[] receiveData = new byte[1024];

            // Đọc câu từ người dùng
            System.out.print("Enter a sentence: ");
            String sentence = inFromUser.readLine().trim();  // Loại bỏ ký tự ngắt dòng
            sendData = sentence.getBytes();

            // Tạo và gửi gói tin đến server
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
            clientSocket.send(sendPacket);

            // Nhận phản hồi từ server
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            clientSocket.receive(receivePacket);

            // Chuyển đổi dữ liệu nhận thành chuỗi
            String modifiedSentence = new String(receivePacket.getData(), 0, receivePacket.getLength()).trim(); // Đảm bảo cắt dữ liệu đúng
            System.out.println("FROM SERVER: " + modifiedSentence);

            clientSocket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

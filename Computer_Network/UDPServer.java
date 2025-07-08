import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPServer {
    public static void main(String[] args) {
        try {
            // Tạo socket UDP server với cổng 9876
            DatagramSocket serverSocket = new DatagramSocket(9876);
            System.out.println("UDP Server is running on port 9876...");

            // Mảng byte để nhận và gửi dữ liệu
            byte[] receiveData = new byte[1024];

            // Vòng lặp server
            while (true) {
                // Tạo DatagramPacket để nhận dữ liệu
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                serverSocket.receive(receivePacket);

                // Chuyển dữ liệu nhận thành chuỗi
                String sentence = new String(receivePacket.getData()).trim();
                InetAddress IPAddress = receivePacket.getAddress();
                int port = receivePacket.getPort();

                // Chuyển chuỗi thành chữ hoa và gửi lại client
                String capitalizedSentence = sentence.toUpperCase();
                byte[] sendData = capitalizedSentence.getBytes();

                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
                serverSocket.send(sendPacket);

                System.out.println("Received: " + sentence + " | Sent: " + capitalizedSentence);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

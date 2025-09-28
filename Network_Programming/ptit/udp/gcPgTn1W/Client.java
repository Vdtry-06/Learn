package ptit.udp.gcPgTn1W;

import java.io.IOException;
import java.net.*;
import java.util.*;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;

    public static void main(String[] args) throws IOException {

        String studentCode = "B22DCCN866";
        String qCode = "gcPgTn1W";

        // Bước 1: Tạo đối tượng DatagramSocket với số cổng xác định
        DatagramSocket socket = new DatagramSocket();

        InetAddress address = InetAddress.getByName(SERVER_HOST);

        // Bước 2: Khai báo bộ đệm xuất/nhập hay outBuffer/inBuffer dạng mảng kiểu byte
        byte[] inBuffer = new byte[1024];
        byte[] outBuffer;

        // Tạo tin từ Client
        String message = ";" + studentCode + ";" + qCode;
        // Chuyển sang dạng byte
        outBuffer = message.getBytes();

        // Bước 3: Khai báo đối tượng DatagramPacket để gửi/nhận
        DatagramPacket outPacket = new DatagramPacket(
                outBuffer, outBuffer.length, address, SERVER_PORT
        );

        // Bước 4: Thực hiện gửi gói tin
        socket.send(outPacket);

        // Nhận phản hồi từ server
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);
        String serverResponse = new String(inPacket.getData(), 0, inPacket.getLength());
        String[] arr = serverResponse.split(";");
        String requestId = arr[0];
        String stringNumbers = arr[1];
        String [] parts = stringNumbers.split(",");
        List<Integer> numbers = new ArrayList<>();
        for (String part : parts) {
            numbers.add(Integer.parseInt(part));
        }
        Collections.sort(numbers);
        String sendServer = requestId + ";"  + Integer.toString(numbers.getLast())+ "," + Integer.toString(numbers.getFirst());
        outBuffer = sendServer.getBytes();

        outPacket = new DatagramPacket(
                outBuffer, outBuffer.length, address, SERVER_PORT
        );

        socket.send(outPacket);

        socket.isClosed();

    }
}

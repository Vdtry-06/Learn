package ptit.udp.string.LpgrBFWg;

import java.io.IOException;
import java.net.*;
import java.util.ArrayList;
import java.util.Collections;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2208;

    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        byte[] inBuffer = new byte[1024];
        byte[] outBuffer;

        String clientMessage = ";B22DCCN866;LpgrBFWg";
        outBuffer = clientMessage.getBytes();
        DatagramPacket outPacket = new DatagramPacket(
                outBuffer,
                outBuffer.length,
                address,
                SERVER_PORT
        );
        socket.send(outPacket);

        DatagramPacket inPacket = new DatagramPacket(
                inBuffer,
                inBuffer.length
        );
        socket.receive(inPacket);
        String serverResponse = new String(inPacket.getData(), 0, inPacket.getLength());

        String[] arr = serverResponse.split(";");
        String requestId = arr[0];
        ArrayList<String> list = new ArrayList<>();
        String[] parts = arr[1].split(" ");
        for (String s: parts) list.add(s);
        list.sort(Collections.reverseOrder(String.CASE_INSENSITIVE_ORDER));
        String sendServer = requestId + ";";
        for (String s : list) {
            sendServer += s + ",";
        }
        sendServer = sendServer.substring(0, sendServer.length() - 1);

        outBuffer = sendServer.getBytes();
        outPacket = new DatagramPacket(
                outBuffer,
                outBuffer.length,
                address,
                SERVER_PORT
        );
        socket.send(outPacket);

        socket.isClosed();
    }
}

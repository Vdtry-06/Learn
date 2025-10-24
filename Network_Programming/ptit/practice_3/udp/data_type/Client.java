package ptit.practice_3.udp.data_type;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.Collections;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;

    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        String message = ";B22DCCN866;ykwtDkSg";
        byte[] inBuffer = new byte[1024];
        byte[] outBuffer = message.getBytes();

        DatagramPacket outPacket = new DatagramPacket(
                outBuffer,
                outBuffer.length,
                address,
                SERVER_PORT
        );

        socket.send(outPacket);

        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);
        String response = new String(inPacket.getData(), 0, inPacket.getLength());
        String []arr = response.split(";");
        String []parts = arr[1].split(",");
        ArrayList<Chracter> list = new ArrayList<>();
        for (String s : parts) {
            String []div = s.split(":");
            list.add(new Chracter(Integer.parseInt(div[1]), div[0]));
        }
        Collections.sort(list);
        String request = arr[0] + ";";
        for (Chracter c : list) {
            request += c.getText() + ",";
        }
        request = request.substring(0, request.length() - 1);
        outBuffer = request.getBytes();
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

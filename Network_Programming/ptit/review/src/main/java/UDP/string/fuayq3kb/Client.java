package UDP.string.fuayq3kb;

import java.io.IOException;
import java.net.*;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2208;
    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        byte[] outBuffer = ";B22DCCN866;fuayq3kb".getBytes();
        DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        byte[] inBuffer = new byte[1024];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String[] arr = new String(inPacket.getData(), 0, inPacket.getLength()).split(";");
        String requestId = arr[0];
        String data = arr[1];
        String[] str = data.split(" ");
        String send = "";
        for (String s : str) {
            send += s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase() + " ";
        }
        send = send.substring(0, send.length() - 1);

        outBuffer = (requestId + ";" + send).getBytes();
        outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        socket.isClosed();
    }
}

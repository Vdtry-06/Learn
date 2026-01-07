package UDP.data_type.xPEHzR23;

import java.io.IOException;
import java.net.*;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;
    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        byte[] outBuffer = ";B22DCCN866;xPEHzR23".getBytes();
        DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        byte[] inBuffer = new byte[1024];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String[] arr = new String(inPacket.getData(),0, inPacket.getLength()).split(";");
        String requestId = arr[0];
        String num = arr[1];
        int s = 0;
        for (int i = 0; i < num.length(); i++) {
            int n = num.charAt(i) - '0';
            s += n;
        }

        outBuffer = (requestId + ";" + s).getBytes();
        outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        socket.isClosed();
    }
}

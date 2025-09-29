package ptit.udp.data_type.oeHDpiCC;

import java.io.IOException;
import java.math.BigInteger;
import java.net.*;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;

    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        byte[] inBuffer = new byte[1024];
        byte[] outBuffer;

        String message = ";B22DCCN866;oeHDpiCC";
        outBuffer = message.getBytes();
        DatagramPacket outPacket = new DatagramPacket(
                outBuffer,
                outBuffer.length,
                address,
                SERVER_PORT
        );
        socket.send(outPacket);

        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String serverResponse = new String(inPacket.getData(), 0, inPacket.getLength());
        String[] arr = serverResponse.split(";");
        String requestId = arr[0];
        BigInteger a = new BigInteger(arr[1]);
        BigInteger b = new BigInteger(arr[2]);
        BigInteger sum = a.add(b);
        BigInteger subtract = a.subtract(b);
        String sendServer = requestId + ";" + sum + "," + subtract;
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

package ptit.udp.string.I08VNVZL;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2208;

    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        String clientMessage = ";B22DCCN866;I08VNVZL";
        byte[] outBuffer = clientMessage.getBytes();
        DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        byte[] inBuffer = new byte[1024];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String serverResponse = new String(inPacket.getData(), 0, inPacket.getLength());
        String[] parts = serverResponse.split(";");
        String requestId = parts[0];
        String[] data = parts[1].split(" ");
        String newData = "";
        for (String s: data) {
            newData += s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase() + " ";
        }
        newData = newData.substring(0, newData.length() - 1);
        String sendServer = requestId + ";" + newData;
        outBuffer = sendServer.getBytes();
        outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        socket.close();
    }
}

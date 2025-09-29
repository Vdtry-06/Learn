package ptit.udp.data_type.wdapS6IR;

import java.io.IOException;
import java.net.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;

    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();

        InetAddress address = InetAddress.getByName(SERVER_HOST);

        byte[] inBuffer = new byte[1024];
        byte[] outBuffer;

        String message = ";B22DCCN866;wdapS6IR";
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
        String stringNumber = arr[1];
        String[] parts = stringNumber.split(",");
        ArrayList<Integer> numbers = new ArrayList<>();
        for (String s: parts) {
            numbers.add(Integer.parseInt(s));
        }
        Collections.sort(numbers);
        int secondMin = numbers.get(1);
        int secondMax = numbers.get(numbers.size() - 2);
        String sendServer = requestId + ";" + secondMax + "," + secondMin;

        outBuffer = sendServer.getBytes();
        outPacket = new DatagramPacket(
                outBuffer, outBuffer.length, address, SERVER_PORT
        );
        socket.send(outPacket);

        socket.isClosed();
    }
}

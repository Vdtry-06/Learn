package ptit.practice_3.udp.string;

import ptit.practice_3.udp.data_type.Chracter;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.Collections;

import static java.lang.Math.pow;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2208;

    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        String message = ";B22DCCN866;lk34WywL";

        byte[] outBuffer = message.getBytes();
        DatagramPacket outPacket = new DatagramPacket(
                outBuffer,
                outBuffer.length,
                address,
                SERVER_PORT
        );

        socket.send(outPacket);

        byte[] inBuffer = new byte[1024];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String response = new String(inPacket.getData(), 0, inPacket.getLength());
        String []arr = response.split(";");
        String []binary = arr[1].split(",");
        int b1 = toInteger(binary[0]);
        int b2 = toInteger(binary[1]);
        int sum = b1 + b2;
        String resquest = arr[0] + ";" + sum;
        outBuffer = resquest.getBytes();
        outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        socket.isClosed();
    }

    public static int toInteger(String b) {
        int cnt = 0, dec = 0;
        for (int i = b.length() - 1; i >= 0; i--) {
            if (b.charAt(i) == '1') {
                dec += pow(2, cnt);
            }
            cnt++;
        }
        return dec;
    }
}

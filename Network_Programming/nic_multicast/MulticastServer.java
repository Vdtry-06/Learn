package nic_multicast;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class MulticastServer {
    public static void main(String[] args) throws IOException, InterruptedException {
        DatagramSocket server = new DatagramSocket();
        System.out.println("server start send message ...");
        int i = 0;
        while (true) {
            String strMessage = "message " + i;
            byte[] data = strMessage.getBytes();
            DatagramPacket dp = new DatagramPacket(data, data.length, InetAddress.getByName("224.2.2.3"), 2207);
            server.send(dp);
            System.out.println("sent: " + strMessage);
            Thread.sleep(2000);
            i++;
        }
    }
}

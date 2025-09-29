package ptit.udp.object._4w6fk0Vz;

import UDP.Student;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2209;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        String clientMessage = ";B22DCCN866;4w6fk0Vz";

        byte[] outBuffer = clientMessage.getBytes();
        DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        byte[] inBuffer = new byte[1024];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String requestId = new String(inPacket.getData(), 0, 8);
        ByteArrayInputStream bis = new ByteArrayInputStream(inPacket.getData(), 8, inPacket.getLength() - 8);
        ObjectInputStream ois = new ObjectInputStream(bis);
        Student student = (Student) ois.readObject();
        ois.close();

        student.setName(student.getName());
        student.setEmail(student.getEmail());

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bos);
        oos.writeObject(student);
        oos.flush();

        byte[] requestIdBytes = requestId.getBytes();
        byte[] objectBytes = bos.toByteArray();

        outBuffer = new byte[requestIdBytes.length + objectBytes.length];
        for (int i = 0; i < 8; i++) outBuffer[i] = requestIdBytes[i];
        for (int i = 0; i < objectBytes.length; i++) outBuffer[8 + i] = objectBytes[i];
        outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        socket.close();
    }
}

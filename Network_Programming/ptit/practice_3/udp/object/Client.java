package ptit.practice_3.udp.object;

import UDP.Employee;

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

        String message = ";B22DCCN866;RRjU42ge";

        byte[] outBuffer = message.getBytes();
        DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        byte[] inBuffer = new byte[1024];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String requestId = new String(inPacket.getData(), 0, 8);
        ByteArrayInputStream bis = new ByteArrayInputStream(inPacket.getData(), 8, inPacket.getLength() - 8);
        Employee employee = (Employee) new ObjectInputStream(bis).readObject();

        employee.updateName();
        employee.updateSalary();
        employee.updateHireDate();

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bos);
        oos.writeObject(employee);
        oos.flush();

        byte[] requestIdBytes = requestId.getBytes();
        byte[] objectBytes = bos.toByteArray();
        outBuffer = new byte[requestIdBytes.length + objectBytes.length];
        System.arraycopy(requestIdBytes, 0, outBuffer, 0, 8);
        System.arraycopy(objectBytes, 0, outBuffer, 8, objectBytes.length);

        outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        socket.isClosed();
    }
}

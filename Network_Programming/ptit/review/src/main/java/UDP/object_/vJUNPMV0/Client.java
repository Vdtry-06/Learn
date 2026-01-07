package UDP.object_.vJUNPMV0;

import UDP.Employee;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName("203.162.10.109");

        byte[] outBuffer = ";B22DCCN866;vJUNPMV0".getBytes();
        DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, 2209);
        socket.send(outPacket);

        byte[] inBuffer = new byte[1024];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        String requestId = new String(inPacket.getData(), 0, 8);
        ByteArrayInputStream bis = new ByteArrayInputStream(inPacket.getData(), 8, inPacket.getLength() - 8);
        ObjectInputStream ois = new ObjectInputStream(bis);
        Employee employee = (Employee) ois.readObject();
        ois.close();

        employee.updateName();
        employee.updateSalary();
        employee.updateHireDate();

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bos);
        oos.writeObject(employee);
        oos.close();

        byte[] employeeBytes = bos.toByteArray();

        outBuffer = new byte[8 + employeeBytes.length];

        System.arraycopy(requestId.getBytes(), 0, outBuffer, 0, 8);
        System.arraycopy(employeeBytes, 0, outBuffer, 8, employeeBytes.length);

        outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, 2209);
        socket.send(outPacket);

        socket.close();

    }
}

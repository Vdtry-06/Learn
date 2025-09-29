package ptit.udp.object.wfDDIqxP;

import UDP.Customer;

import java.io.*;
import java.net.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2209;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);


        String clientMessage = ";B22DCCN866;wfDDIqxP";
        byte[] outBuffer = clientMessage.getBytes();
        DatagramPacket outPacket = new DatagramPacket(
                outBuffer,
                outBuffer.length,
                address,
                SERVER_PORT
        );
        socket.send(outPacket);

        byte[] inBuffer = new byte[65535];
        DatagramPacket inPacket = new DatagramPacket(
                inBuffer,
                inBuffer.length
        );
        socket.receive(inPacket);

        String requestId = new String(inPacket.getData(), 0, 8);

        ByteArrayInputStream bis = new ByteArrayInputStream(inPacket.getData(), 8, inPacket.getLength() - 8);
        ObjectInputStream ois = new ObjectInputStream(bis);
        Customer customer = (Customer) ois.readObject();
        System.out.println(requestId + " " + customer.toString());
        ois.close();

        fixName(customer);
        System.out.println(customer.getName());
        fixDate(customer);
        System.out.println(customer.getDayOfBirth());
        fixUsername(customer);
        System.out.println(customer.getUserName());

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bos);
        oos.writeObject(customer);
        oos.flush();

        byte[] requestIdBytes = requestId.getBytes();
        byte[] objectBytes = bos.toByteArray();

        outBuffer = new byte[requestIdBytes.length + objectBytes.length];
        for (int i = 0; i < 8; i++) outBuffer[i] = requestIdBytes[i];
        for (int i = 0; i < objectBytes.length; i++) outBuffer[8 + i] = objectBytes[i];

        DatagramPacket responsePacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(responsePacket);

        socket.close();
    }

    private static void fixName(Customer customer) {
        String[] parts = customer.getName().split(" ");
        String changeName = parts[parts.length - 1].toUpperCase() + ", ";
        for (int i = 0; i < parts.length - 1; i++) {
            changeName += parts[i].substring(0, 1).toUpperCase() + parts[i].substring(1).toLowerCase() + " ";
        }
        changeName = changeName.substring(0, changeName.length() - 1);
        customer.setName(changeName);
    }

    private static void fixDate(Customer customer) {
        DateTimeFormatter in = DateTimeFormatter.ofPattern("MM-dd-yyyy");
        DateTimeFormatter out = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate date = LocalDate.parse(customer.getDayOfBirth(), in);
        String formatDate = date.format(out);
        customer.setDayOfBirth(formatDate);
    }

    private static void fixUsername(Customer customer) {
        String[] parts = customer.getName().split(" ");
        String username = "";
        for (int i = 1; i < parts.length; i++) {
            username += parts[i].substring(0, 1).toLowerCase();
        }
        username += parts[0].toLowerCase();
        username = username.substring(0, username.length() - 1);
        customer.setUserName(username);
    }
}

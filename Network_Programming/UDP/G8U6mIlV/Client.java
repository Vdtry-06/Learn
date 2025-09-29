package UDP.G8U6mIlV;

import UDP.Product;

import java.io.*;
import java.net.*;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2209;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName(SERVER_HOST);

        // B1: gửi thông điệp
        String message = ";B22DCCN866;G8U6mIlV";
        byte[] outBuffer = message.getBytes();
        DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
        socket.send(outPacket);

        // B2: nhận dữ liệu từ server
        byte[] inBuffer = new byte[65535];
        DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
        socket.receive(inPacket);

        // Tách requestId (8 byte đầu)
        String requestId = new String(inPacket.getData(), 0, 8);

        // Deserialize object Product
        ByteArrayInputStream bis = new ByteArrayInputStream(inPacket.getData(), 8, inPacket.getLength() - 8);
        ObjectInputStream ois = new ObjectInputStream(bis);
        Product product = (Product) ois.readObject();
        ois.close();

        System.out.println("Received product: " + product.getName() + " - " + product.getQuantity());

        // B3: sửa product
        fixProductName(product);
        fixProductQuantity(product);

        System.out.println("Fixed product: " + product.getName() + " - " + product.getQuantity());

        // B4: Serialize lại object
        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(bos);
        oos.writeObject(product);
        oos.flush();
        byte[] productBytes = bos.toByteArray();

        // Ghép requestId (8 byte đầu) + productBytes

        // C1:
        byte[] sendBuffer = new byte[8 + productBytes.length];
        for (int i = 0; i < 8; i++) {
            sendBuffer[i] = requestId.getBytes()[i];
        }
        for (int i = 0; i < productBytes.length; i++) {
            sendBuffer[8 + i] = productBytes[i];
        }
        /*
            C2:
            byte[] sendBuffer = new byte[8 + productBytes.length];
            System.arraycopy(requestId.getBytes(), 0, sendBuffer, 0, 8);
            System.arraycopy(productBytes, 0, sendBuffer, 8, productBytes.length);
                src → mảng nguồn
                srcPos → vị trí bắt đầu trong mảng nguồn
                dest → mảng đích
                destPos → vị trí bắt đầu trong mảng đích
                length → số phần tử copy
        */

        /* C3:
            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            outputStream.write(requestId.getBytes(), 0, 8);
            outputStream.write(productBytes);
            byte[] sendBuffer = outputStream.toByteArray();
         */

        DatagramPacket responsePacket = new DatagramPacket(sendBuffer, sendBuffer.length, address, SERVER_PORT);
        socket.send(responsePacket);

        socket.close();
    }

    // Đổi ngược từ đầu/cuối trong name
    private static void fixProductName(Product product) {
        String[] parts = product.getName().split(" ");
        if (parts.length > 1) {
            String temp = parts[0];
            parts[0] = parts[parts.length - 1];
            parts[parts.length - 1] = temp;
        }
        product.setName(String.join(" ", parts));
    }

    // Đảo ngược chữ số của quantity
    private static void fixProductQuantity(Product product) {
        String s = new StringBuilder(String.valueOf(product.getQuantity())).reverse().toString();
        product.setQuantity(Integer.parseInt(s));
    }
}

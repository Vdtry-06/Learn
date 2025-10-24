package ptit.tcp.object_stream.APT0GOea;

import TCP.Address;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

import static ptit.tcp.object_stream.APT0GOea.Address.processAddressLine;
import static ptit.tcp.object_stream.APT0GOea.Address.processPostalCode;


public class Client {

    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2209;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

        // a. Gửi chuỗi "studentCode;qCode"
        String studentCode = "B22DCCN866";
        String qCode = "APT0GOea";
        out.writeObject(studentCode + ";" + qCode);
        out.flush();

        // b. Nhận đối tượng Address
        Address address = (Address) in.readObject();
        System.out.println("received server: " + address);

        address.setAddressLine(processAddressLine(address.getAddressLine()));
        address.setPostalCode(processPostalCode(address.getPostalCode()));

        out.writeObject(address);
        out.flush();
        System.out.println("sent server: " + address);

        socket.close();
        in.close();
        out.close();
    }
}

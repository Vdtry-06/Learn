package ptit.practice_3.tcp.object_stream;

import TCP.Customer;

import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Socket socket = new Socket("203.162.10.109", 2209);
        socket.setSoTimeout(5000);

        String message = "B22DCCN866;yUABtJ84";

        ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

        out.writeObject(message);
        out.flush();

        Customer customer = (Customer) in.readObject();
        customer.updateUsername();
        customer.updateName();
        customer.updateDate();

        out.writeObject(customer);
        out.flush();

        socket.close();
        in.close();
        out.close();
    }
}

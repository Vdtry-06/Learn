package TCP.object_stream.rSRgL7QI;

import TCP.Customer;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Socket socket = new Socket("203.162.10.109", 2209);

        socket.setSoTimeout(5000);

        ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

        out.writeObject("B22DCCN866;rSRgL7QI");
        out.flush();

        Customer customer = (Customer) in.readObject();

        customer.updateUserName();
        customer.updateName();
        customer.updateDayOfBirth();

        out.writeObject(customer);
        out.flush();

        socket.close();
        in.close();
        out.close();

    }
}

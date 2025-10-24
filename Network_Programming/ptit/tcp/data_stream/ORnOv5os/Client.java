package ptit.tcp.data_stream.ORnOv5os;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;

    public static void main(String[] args) throws IOException {

        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        DataInputStream in = new DataInputStream(socket.getInputStream());
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());

        String studentCode = "B22DCCN866";
        String qCode = "ORnOv5os";
        String clientMessage = studentCode + ";" + qCode;

        out.writeUTF(clientMessage);
        out.flush();
        System.out.println("Client received: " + clientMessage);

        int a = in.readInt();
        int b = in.readInt();
        System.out.println("a: " + a);
        System.out.println("b: " + b);
        int sum = a + b;
        int mult = a * b;

        out.writeInt(sum);
        out.flush();
        out.writeInt(mult);
        out.flush();
        System.out.println("Server received sum: " + sum);
        System.out.println("Server received sum: " + mult);

        socket.close();
        in.close();
        out.close();
    }
}

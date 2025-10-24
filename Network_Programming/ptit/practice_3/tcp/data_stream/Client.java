package ptit.practice_3.tcp.data_stream;

import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("203.162.10.109", 2207);
        socket.setSoTimeout(5000);

        String message = "B22DCCN866;AnqTI6NQ";

        DataInputStream in = new DataInputStream(socket.getInputStream());
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());

        out.writeUTF(message);
        out.flush();

        int a = in.readInt();
        int b = in.readInt();

        out.writeInt(a + b);
        out.flush();
        out.writeInt(a * b);

        socket.close();
        in.close();
        out.close();
    }
}

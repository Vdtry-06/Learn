package TCP.data_stream.rkPzbI3N;

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
        out.writeUTF("B22DCCN866;rkPzbI3N");
        out.flush();

        Integer n = in.readInt();
        System.out.println(n);
        System.out.println(binary(n));
        System.out.println(hexa(n));
        out.writeUTF(binary(n) + ";" + hexa(n));
        out.flush();

        socket.close();
        in.close();
        out.close();
    }

    private static String binary(int n) {
        StringBuilder s = new StringBuilder();
        while(n != 0) {
            s.append(n % 2);
            n /= 2;
        }
        s.reverse();
        return s.toString();
    }

    private static String hexa(int n) {
        String hex = "0123456789ABCDEF";
        StringBuilder s = new StringBuilder();
        while (n != 0) {
            s.append(hex.charAt(n % 16));
            n /= 16;
        }
        s.reverse();
        return s.toString();
    }
}

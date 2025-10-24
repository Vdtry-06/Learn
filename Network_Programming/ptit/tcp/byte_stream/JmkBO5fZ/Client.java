package ptit.tcp.byte_stream.JmkBO5fZ;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

import static java.lang.Math.sqrt;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2206;
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        InputStream in = socket.getInputStream();
        OutputStream out = socket.getOutputStream();

        String studentCode = "B22DCCN866";
        String qCode = "JmkBO5fZ";

        String clientMessage = studentCode + ";" + qCode;
        out.write(clientMessage.getBytes());
        out.flush();
        System.out.println("Client sent: " + clientMessage);

        byte[] buffer = new byte[1024];
        int bytesRead = in.read(buffer);
        if (bytesRead != -1) {
            String serverResponse = new String(buffer, 0, bytesRead);
            System.out.println("Server response received: " + serverResponse);
            String result = sumPrime(serverResponse);
            out.write(result.getBytes());
            out.flush();
        }
        socket.close();
        in.close();
        out.close();
    }

    private static String sumPrime(String data) {
        String[] arr = data.split(",");
        int sum = 0;
        for (String s : arr) {
            int n = Integer.parseInt(s);
            if (prime(n)) {
                sum += n;
            }
        }
        return Integer.toString(sum);
    }

    private static boolean prime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

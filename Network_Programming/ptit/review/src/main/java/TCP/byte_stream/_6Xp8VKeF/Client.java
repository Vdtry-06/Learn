package TCP.byte_stream._6Xp8VKeF;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2206;
    public static void main (String[] args) throws IOException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        InputStream in = socket.getInputStream();
        OutputStream out = socket.getOutputStream();

        out.write("B22DCCN866;6Xp8VKeF".getBytes());
        out.flush();

        byte[] buffer = new byte[1024];
        int bytesRead = in.read(buffer);
        if (bytesRead != -1) {
            String[] arr = new String(buffer, 0, bytesRead).split("\\|");
            Long s = 0L;
            for (int i = 0; i < arr.length; i++) {
                s += Long.parseLong(arr[i]);
            }
            System.out.println(s);

            out.write(s.toString().getBytes());
            out.flush();
        }

        socket.close();
        in.close();
        out.close();
    }
}

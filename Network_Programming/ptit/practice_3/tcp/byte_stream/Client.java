package ptit.practice_3.tcp.byte_stream;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("203.162.10.109", 2206);
        socket.setSoTimeout(5000);

        String message = "B22DCCN866;YcN07uSJ";
        InputStream in = socket.getInputStream();
        OutputStream out = socket.getOutputStream();

        out.write(message.getBytes());
        out.flush();

        byte[] buffer = new byte[1024];
        int bytesRead = in.read(buffer);
        if (bytesRead != -1) {
            String response = new String(buffer, 0, bytesRead);
            int n = Integer.parseInt(response);
            List<Integer> arr = new ArrayList<>();
            arr.add(n);
            while (n != 1) {
                if (n % 2 == 0) {
                    n /= 2;
                    arr.add(n);
                } else {
                    n = 3 * n + 1;
                    arr.add(n);
                }
            }
            String request = "";
            for (Integer num : arr) {
                request += num + " ";
            }
            request = request.substring(0, request.length() - 1) + "; ";
            request += arr.size() + "";

            out.write(request.getBytes());
            out.flush();
        }

        socket.close();
        in.close();
        out.close();
    }
}

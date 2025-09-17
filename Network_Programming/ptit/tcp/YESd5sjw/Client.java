package ptit.tcp.YESd5sjw;

import java.io.*;
import java.net.Socket;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2206;
    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        String studentCode = "B22DCCN866";
        String qCode = "YESd5sjw";

        InputStream in = socket.getInputStream();
        OutputStream out = socket.getOutputStream();

        // gửi tới server
        String clientMessage = studentCode + ";" + qCode;
        out.write(clientMessage.getBytes());
        out.flush();

        // đọc dữ liệu từ server
        byte[] buffer = new byte[BUFFER_SIZE];
        int bytesRead = in.read(buffer);
        if (bytesRead > 0) {
            String serverResponse = new String(buffer, 0, bytesRead);
            String result = process(serverResponse);

            // gửi lại kết quả
            out.write(result.getBytes());
            out.flush();
        }

        in.close();
        out.close();
        socket.close();
    }

    private static String process(String serverResponse) {
        String[] arr = serverResponse.split("\\|");
        long sum = 0;
        for (String s : arr) {
            sum += Long.parseLong(s.trim());
        }
        return Long.toString(sum);
    }
}
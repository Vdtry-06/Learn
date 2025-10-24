package ptit.practice_3.tcp.character_stream;

import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("203.162.10.109", 2208);
        socket.setSoTimeout(5000);

        String message = "B22DCCN866;rYSg9pHz";

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        out.println(message);
        String request = "";

        String []arr = in.readLine().split(", ");
        for (String s : arr) {
            if (s.substring(s.length() - 3, s.length()).equals("edu")) {
                request += s + ", ";
            }
        }

        request = request.substring(0, request.length() - 2);
        out.println(request);

        socket.close();
        in.close();
        out.close();
    }
}

package TCP.character_stream.k0vvP2m5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2208;
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        out.println("B22DCCN866;k0vvP2m5");
        out.flush();
        String s = in.readLine();
        System.out.println(s);

        int [] f = new int[256];

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') f[c]++;
        }

        String request = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (f[c] != 0) {
                request += s.charAt(i);
                f[c] = 0;
            }
        }

        out.println(request);
        out.flush();

        socket.close();
        in.close();
        out.close();
    }
}

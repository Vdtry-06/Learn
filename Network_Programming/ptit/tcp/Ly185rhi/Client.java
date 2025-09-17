package ptit.tcp.Ly185rhi;

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

        String studentCode = "B22DCCN866";
        String qCode = "Ly185rhi";
        String clientMessage = studentCode + ";" + qCode;
        out.println(clientMessage);

        String[] arr = in.readLine().split(" ");
        System.out.println("Client received: ");
        for (String s : arr) System.out.print(s + " ");
        System.out.println();
        StringBuilder sb = new StringBuilder();
        for (String s : arr) {
            String res = Character(s);
            sb.append(res + " ");
        }
        sb.deleteCharAt(sb.length() - 1);
        out.println(sb.toString());
        System.out.println("Client sent: " + sb.toString());

        socket.close();
        in.close();
        out.close();
    }

    private static String Character(String s) {
        s = new StringBuilder(s).reverse().toString();
        Integer[] f = new Integer[s.length()];
        f[0] = 1;
        StringBuilder res = new StringBuilder();
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                f[i] = f[i - 1] + 1;
            } else {
                if (f[i - 1] > 1) res.append(s.charAt(i - 1)).append(f[i - 1]);
                else res.append(s.charAt(i - 1));
                f[i] = 1;
            }
        }

        if (f[s.length() - 1] > 1) res.append(s.charAt(s.length() - 1)).append(f[s.length() - 1]);
        else res.append(s.charAt(s.length() - 1));

        return res.toString();
    }
}

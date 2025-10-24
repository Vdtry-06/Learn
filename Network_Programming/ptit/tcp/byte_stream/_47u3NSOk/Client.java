package ptit.tcp.byte_stream._47u3NSOk;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;

public class Client {
    private static String SERVER_HOST = "203.162.10.109";
    private static int SERVER_PORT = 2208;
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        String studentCode = "B22DCCN866";
        String qCode = "47u3NSOk";
        String clientMessage = studentCode + ";" + qCode;
        out.println(clientMessage);

        String[] arr = in.readLine().split(" ");
        System.out.println("Client received: ");
        for (String s : arr) { System.out.print(s + " "); }
        System.out.println();
        ArrayList<Characture> list = new ArrayList<>();
        int cnt = 0;
        for (String s : arr) {
            list.add(new Characture(s.length(), cnt++, s));
        }
        Collections.sort(list);
        String res = "";
        for (Characture s : list) res += s.getVal() + ", ";
        res = res.substring(0, res.length() - 2);
        out.println(res);
        System.out.println("Client received: " + res);

        socket.close();
        in.close();
        out.close();

    }
}

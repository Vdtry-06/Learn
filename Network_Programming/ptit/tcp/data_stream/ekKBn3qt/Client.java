package ptit.tcp.data_stream.ekKBn3qt;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;

import static java.lang.Math.min;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        DataInputStream in = new DataInputStream(socket.getInputStream());
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());

        String studentCode = "B22DCCN866";
        String qCode = "ekKBn3qt";
        String clientMessage = studentCode + ";" + qCode;
        out.writeUTF(clientMessage);
        out.flush();

        int k = in.readInt();
        System.out.println("Client received: " + k);
        String[] arr = in.readUTF().split(",");
        System.out.println("Client received: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        String res = reverseFollowK(k, arr);
        System.out.println("Server recieved: " + res);
        out.writeUTF(res);
        out.flush();

        socket.close();
        in.close();
        out.close();
    }

    private static String reverseFollowK(int k, String[] arr) {
        ArrayList<Integer> num = new ArrayList<>();
        for (String s : arr) num.add(Integer.parseInt(s));
        ArrayList<Integer> ans = new ArrayList<>();
        int n = num.size();
        for (int i = 0; i < n; i++) ans.add(0);
        for (int i = 0; i < n; i++) {
            int start = i / k * k;
            int m = min(k, n - start);
            int mod = i - start;
            int reverseIdx = start + m - mod - 1;
            ans.set(reverseIdx, num.get(i));
        }
        String res = "";
        for (int i = 0; i < num.size(); i++) {
            res += ans.get(i) + ",";
        }
        res = res.substring(0, res.length() - 1);
        return res;
    }
}

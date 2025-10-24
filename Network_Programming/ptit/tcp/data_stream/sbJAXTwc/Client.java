package ptit.tcp.data_stream.sbJAXTwc;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;

import static java.lang.Math.abs;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        DataInputStream in = new DataInputStream(socket.getInputStream());
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());

        String studentCode = "B22DCCN866";
        String qCode = "sbJAXTwc";
        String clientMessage = studentCode + ";" + qCode;
        out.writeUTF(clientMessage);

        String serverResponse = in.readUTF();
        ArrayList<Integer> arr = reverseNumber(serverResponse);
        out.writeInt(arr.get(0));
        out.flush();
        System.out.println("Server response: " + arr.get(0));

        out.writeInt(arr.get(1));
        out.flush();
        System.out.println("Server response: " + arr.get(1));

        socket.close();
        in.close();
        out.close();
    }

    private static ArrayList<Integer> reverseNumber(String data) {
        String[] arr = data.split(",");
        ArrayList<Integer> num = new ArrayList<>();
        for (String s : arr) {
            int n = Integer.parseInt(s);
            num.add(n);
        }
        int cnt = 0, sum = 0;
        if (num.size() <= 1) {
            cnt = 0;
            sum = 0;
        } else {
            for (int i = 1; i < num.size() - 1; i++) {
                if ((num.get(i - 1) < num.get(i) && num.get(i) > num.get(i + 1))
                        || (num.get(i - 1) > num.get(i) && num.get(i) < num.get(i + 1))) {
                    cnt++;
                }
                sum += abs(num.get(i) - num.get(i - 1));
            }
            sum += abs(num.getLast() - num.get(num.size() - 2));
        }

        ArrayList<Integer> res = new ArrayList<>();
        res.add(cnt);
        res.add(sum);
        return res;
    }
}

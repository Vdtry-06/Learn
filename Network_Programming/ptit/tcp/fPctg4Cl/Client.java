package ptit.tcp.fPctg4Cl;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;


import static java.lang.Math.abs;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2206;
    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) throws IOException {
        String studentCode = "B22DCCN866";
        String qCode = "fPctg4Cl";

        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();

        String clientResponse = studentCode + ";" + qCode;

        os.write(clientResponse.getBytes());
        os.flush();

        byte[] buffer = new byte[BUFFER_SIZE];
        int read = is.read(buffer);
        if (read > 0) {
            String serverResponse = new String(buffer, 0, read);
            String result = process(serverResponse);
            System.out.println("Sending: " + result);

            os.write(result.getBytes());
            os.flush();
        }
        socket.close();
        is.close();
        os.close();
    }

    private static String process(String data) {
        String[] arr = data.split(",");
        int sum = 0;
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (String s : arr) {
            int num = Integer.parseInt(s);
            list.add(num);
            sum += num;
        }
        int avg = sum / arr.length;
        int target = 2 * avg;
        int num1 = list.get(0);
        int num2 = list.get(1);
        int minDistance = abs((num1 + num2) - target);
        Collections.sort(list);

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                int currentNum = list.get(i) + list.get(j);
                int distance = abs(currentNum - target);
                if (distance < minDistance) {
                    minDistance = distance;
                    num1 = list.get(i);
                    num2 = list.get(j);
                }
            }
        }
        return Integer.toString(num1) + "," + Integer.toString(num2);
    }
}

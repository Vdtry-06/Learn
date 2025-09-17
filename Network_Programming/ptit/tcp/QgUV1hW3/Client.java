package ptit.tcp.QgUV1hW3;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2207;

    public static void main(String[] args) throws IOException {

        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        String studentCode = "B22DCCN866";
        String qCode = "QgUV1hW3";

        String clientMessage = studentCode + ";" + qCode;

        DataInputStream in = new DataInputStream(socket.getInputStream());
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());

        // Gửi message ban đầu
        out.writeUTF(clientMessage);
        out.flush();
        System.out.println("sent server: " + clientMessage);

        // Nhận số nguyên từ server
        int num = in.readInt();
        System.out.println("received from server: " + num);

        // Gửi kết quả octal
        String result = process(num);

        out.writeUTF(result);
        out.flush();
        System.out.println("sent hex: " + result);

        socket.close();
        in.close();
        out.close();
    }

    private static String process(int num) {
        String octal = changeTo8(num);
        String hexa = changeTo16(num);
        return octal + ";" + hexa;
    }

    private static String changeTo8(int num) {
        if (num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.append(num % 8);
            num /= 8;
        }
        return sb.reverse().toString();
    }

    private static String changeTo16(int num) {
        if (num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        char[] hexMap = "0123456789ABCDEF".toCharArray();
        while (num > 0) {
            sb.append(hexMap[num % 16]);
            num /= 16;
        }
        return sb.reverse().toString();
    }
}

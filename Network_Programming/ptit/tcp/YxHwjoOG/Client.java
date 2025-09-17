package ptit.tcp.YxHwjoOG;

import java.io.*;
import java.net.Socket;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    private static final int SERVER_PORT = 2209;

    public static void main(String[] args) throws IOException, ClassNotFoundException {

        Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
        socket.setSoTimeout(5000);

        ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

        // a. Gửi chuỗi "studentCode;qCode"
        String studentCode = "B22DCCN866";
        String qCode = "YxHwjoOG";
        out.writeObject(studentCode + ";" + qCode);
        out.flush();

        // b. Nhận đối tượng Product
        Product product = (Product) in.readObject();
        System.out.println("received server: " + product);

        // c. Tính discount = tổng các chữ số phần nguyên của price
        int discount = calcDiscount(product.getPrice());
        product.setDiscount(discount);

        // d. Gửi lại Product lên server
        out.writeObject(product);
        out.flush();
        System.out.println("sent: " + product);

        in.close();
        out.close();
        socket.close();
    }

    private static int calcDiscount(double price) {
        long intPart = (long) price;
        int sum = 0;
        while (intPart > 0) {
            sum += intPart % 10;
            intPart /= 10;
        }
        return sum;
    }
}

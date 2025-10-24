package demo;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ConnectException;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket();
            socket.connect(new InetSocketAddress("example.com", 8080), 5000); // timeout 5s

            InputStream in = socket.getInputStream();
            OutputStream out = socket.getOutputStream();

            // send/receive dữ liệu...

        } catch (SocketTimeoutException e) {
            System.err.println("Timeout khi kết nối hoặc đọc dữ liệu: " + e.getMessage());
        } catch (ConnectException e) {
            System.err.println("Không thể kết nối tới server: " + e.getMessage());
        } catch (IOException e) {
            System.err.println("Lỗi IO: " + e.getMessage());
        }
    }

    public void sendWithRetry(String host, int port, byte[] data) {
        int maxRetries = 3;
        int attempt = 0;
        boolean success = false;

        while (attempt < maxRetries && !success) {
            attempt++;
            try (Socket socket = new Socket(host, port)) {
                OutputStream out = socket.getOutputStream();
                out.write(data);
                out.flush();
                success = true;
                System.out.println("Gửi dữ liệu thành công ở lần thử " + attempt);
            } catch (IOException e) {
                System.err.println("Thử lần " + attempt + " thất bại: " + e.getMessage());
                try {
                    Thread.sleep(2000); // delay 2s trước khi thử lại
                } catch (InterruptedException ignored) {}
            }
        }

        if (!success) {
            System.err.println("Gửi thất bại sau " + maxRetries + " lần thử.");
        }

    }


}

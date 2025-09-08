package http;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class HttpClient {
    public static void main(String[] args) throws IOException {
        Socket httpClient = new Socket("127.0.0.1", 8080);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(httpClient.getOutputStream()));
        String strRequest = "GET 127.0.0.1 HTTP/1.1 \r\n"
                + "User-Agent: HTTPClientPTIT 1.0 \r\n"
                + "Host: www.ptit.edu.vn \r\n\r\n";
        bw.write(strRequest);
        bw.flush();

        InputStream is = httpClient.getInputStream();
        byte[] b = new byte[1024];
        while (is.read(b) != -1) {
            System.out.println(new String(b));
        }
        bw.close();
        is.close();
        httpClient.close();
    }
}

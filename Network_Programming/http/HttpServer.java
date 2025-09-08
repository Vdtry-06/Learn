package http;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class HttpServer {
    public static void main(String[]args) throws IOException {
        ServerSocket httpServer = new ServerSocket(8080);
        System.out.println("HTTP Server started on port 8080");
        while (true) {
            Socket httpRequest = httpServer.accept();
            System.out.println("Http request: " + httpRequest);
            // http request
            BufferedReader br = new BufferedReader(new InputStreamReader(httpRequest.getInputStream()));
            String line = br.readLine();
            while(!line.isEmpty()){
                System.out.println(line);
                line = br.readLine();
            }

            // http response
            OutputStream os = httpRequest.getOutputStream();
            String response = "HTTP/1.1 200 OK\r\n\r\n";
            Date today = new Date();

            os.write((response + today).getBytes());

            // close
            br.close();
            httpRequest.close();
        }
    }
}

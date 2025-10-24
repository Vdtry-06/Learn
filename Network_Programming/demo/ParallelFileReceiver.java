package demo;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.net.ServerSocket;
import java.net.Socket;

public class ParallelFileReceiver {
    private static final int PORT = 8080;
    private static final String OUTPUT_FILE = "C:\\Users\\ASUS\\Learn\\Network_Programming\\demo\\output.bin";
    private static final int CHUNK_SIZE = 1024 * 1024; // 1MB

    public static void main(String[] args) throws Exception {
        try (ServerSocket serverSocket = new ServerSocket(PORT);
             RandomAccessFile raf = new RandomAccessFile(OUTPUT_FILE, "rw")) {

            System.out.println("Server đang chạy, chờ nhận file...");

            while (true) {
                Socket socket = serverSocket.accept();
                new Thread(new ChunkHandler(socket, raf)).start();
            }
        }
    }

    static class ChunkHandler implements Runnable {
        private final Socket socket;
        private final RandomAccessFile raf;

        public ChunkHandler(Socket socket, RandomAccessFile raf) {
            this.socket = socket;
            this.raf = raf;
        }

        @Override
        public void run() {
            try (DataInputStream dis = new DataInputStream(socket.getInputStream())) {
                int chunkIndex = dis.readInt();   // nhận index
                int length = dis.readInt();       // nhận độ dài chunk
                byte[] buffer = new byte[length];
                dis.readFully(buffer);            // nhận dữ liệu

                long offset = (long) chunkIndex * CHUNK_SIZE;

                synchronized (raf) {
                    raf.seek(offset);             // nhảy tới đúng vị trí
                    raf.write(buffer);            // ghi chunk vào file
                }

                System.out.println("Đã nhận chunk " + chunkIndex + " (" + length + " bytes)");
            } catch (IOException e) {
                System.err.println("Lỗi khi nhận chunk: " + e.getMessage());
            }
        }
    }
}

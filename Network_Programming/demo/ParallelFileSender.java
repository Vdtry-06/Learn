package demo;

import java.io.DataOutputStream;
import java.io.File;
import java.io.RandomAccessFile;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ParallelFileSender {
    private static final int CHUNK_SIZE = 1024 * 1024; // 1MB
    private static final int THREADS = 4; // số luồng song song

    public static void main(String[] args) throws Exception {
        File file = new File("C:\\Users\\ASUS\\Learn\\Network_Programming\\demo\\bigfile.bin");
        ExecutorService pool = Executors.newFixedThreadPool(THREADS);

        try (RandomAccessFile raf = new RandomAccessFile(file, "r")) {
            long fileSize = file.length();
            int totalChunks = (int) Math.ceil((double) fileSize / CHUNK_SIZE);

            for (int i = 0; i < totalChunks; i++) {
                final int chunkIndex = i;
                pool.submit(() -> {
                    try {
                        long start = chunkIndex * CHUNK_SIZE;
                        long size = Math.min(CHUNK_SIZE, fileSize - start);
                        byte[] buffer = new byte[(int) size];

                        synchronized (raf) {
                            raf.seek(start);
                            raf.readFully(buffer);
                        }

                        // gửi chunk tới server
                        try (Socket socket = new Socket("localhost", 8080);
                             DataOutputStream dos = new DataOutputStream(socket.getOutputStream())) {

                            dos.writeInt(chunkIndex);      // gửi index
                            dos.writeInt(buffer.length);   // gửi độ dài chunk
                            dos.write(buffer);             // gửi dữ liệu
                            dos.flush();
                        }

                        System.out.println("Đã gửi chunk " + chunkIndex);
                    } catch (Exception e) {
                        System.err.println("Lỗi chunk " + chunkIndex + ": " + e.getMessage());
                    }
                });
            }
        }

        pool.shutdown();
        pool.awaitTermination(1, TimeUnit.HOURS);
    }
}

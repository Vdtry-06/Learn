package demo;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Block {

    private final int id;

    public Block(int id) {
        this.id = id;
    }

    // giả lập gửi block
    public static void sendBlock(Block block) throws IOException {
        // 30% xác suất lỗi
        if (Math.random() < 0.3) {
            throw new IOException("Network error khi gửi block " + block.id);
        }
        System.out.println("Đã gửi thành công block " + block.id);
    }

    public static void main(String[] args) throws IOException {
        // tạo danh sách block
        List<Block> fileBlocks = new ArrayList<>();
        for (int i = 1; i <= 5; i++) {
            fileBlocks.add(new Block(i));
        }

        final int MAX_RETRY = 3;

        for (Block block : fileBlocks) {
            boolean sent = false;
            int retries = 0;

            while (!sent && retries < MAX_RETRY) {
                try {
                    sendBlock(block);
                    sent = true;
                } catch (IOException e) {
                    retries++;
                    System.err.println("Lỗi gửi block " + block.id + ", retry lần " + retries);
                }
            }

            if (!sent) {
                throw new IOException("Gửi block " + block.id + " thất bại sau nhiều lần thử");
            }
        }
    }
}

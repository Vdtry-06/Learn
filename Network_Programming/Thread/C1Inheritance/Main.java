package Thread.C1Inheritance;

public class Main {
    public static void main(String[] args) {
        PrintThread a = new PrintThread("A");
        PrintThread b = new PrintThread("B");
        PrintThread c = new PrintThread("C");
        PrintThread d = new PrintThread("D");
        // 4 parallel streams: 4 luồng chạy song song
    }
}

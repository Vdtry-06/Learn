package Thread.C2Runnable;

public class Main {
    public static void main(String[] args) {
        // Create Thread object and pass PrintRunnable to constructor
        // Tạo đối tượng thread và truyền printRunnable vào constructor
        Thread a = new Thread(new PrintRunnable("A"));
        Thread b = new Thread(new PrintRunnable("B"));
        Thread c = new Thread(new PrintRunnable("C"));
        Thread d = new Thread(new PrintRunnable("D"));
    }
}

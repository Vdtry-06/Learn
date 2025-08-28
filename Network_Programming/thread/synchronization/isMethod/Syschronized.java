package thread.synchronization.isMethod;

public class Syschronized {
    public static void main(String[] args) {
        Sender sender = new Sender();
        ThreadSend step1 = new ThreadSend(new String[] {"one", "two", "three"}, sender);
        ThreadSend step2 = new ThreadSend(new String[] {"four", "five", "six"}, sender);
        ThreadSend step3 = new ThreadSend(new String[] {"seven", "eight", "nine"}, sender);

        step1.start();
        step2.start();
        step3.start();
    }
}

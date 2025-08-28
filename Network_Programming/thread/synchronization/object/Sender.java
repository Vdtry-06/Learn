package thread.synchronization.object;

public class Sender {
    public void send(String[] messages) throws InterruptedException {
        System.out.println(Thread.currentThread().getName() + " start send: ");
        for (String message : messages) {
            System.out.println(message);
            Thread.sleep(1000);
        }
    }
}

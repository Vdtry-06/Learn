package thread.unsynchronization;

public class Sender {
    public void send(String[] messages) throws InterruptedException {
        System.out.println(Thread.currentThread().getName() + " start send: ");
        for (int i = 0; i < messages.length; i++) {
            System.out.println(messages[i]);
            Thread.sleep(1000);
        }
    }
}

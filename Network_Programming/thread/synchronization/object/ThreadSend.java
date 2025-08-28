package thread.synchronization.object;

public class ThreadSend extends Thread {
    private String[] messages;
    Sender sender;

    public ThreadSend(String[] messages, Sender sender) {
        this.messages = messages;
        this.sender = sender;
    }

    public void run() {
        synchronized(sender) {
            try {
                sender.send(messages);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

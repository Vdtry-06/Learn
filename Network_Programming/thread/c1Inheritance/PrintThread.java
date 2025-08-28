package thread.c1Inheritance;

public class PrintThread extends Thread {
    private String name;
    public PrintThread(String name) {
        this.name = name;
        start(); // run thread
    }

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + "- Value: " + i + " - Name: " + name);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

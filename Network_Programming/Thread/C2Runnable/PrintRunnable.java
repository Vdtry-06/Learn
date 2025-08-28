package Thread.C2Runnable;

public class PrintRunnable implements Runnable {
    private String name;
    public PrintRunnable(String name) {
        this.name = name;
        Thread thread = new Thread(this);
        thread.start();
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

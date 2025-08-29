package share_data.synchronization;

public class Producer extends Thread {
    SharedData sharedData;
    public Producer(SharedData sharedData) {
        this.sharedData = sharedData;
        this.start();
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            sharedData.produce((int) (Math.random() * 100));
        }
    }
}

package share_data.synchronization;

public class Main {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();
        new Producer(sharedData);
        new Consumer(sharedData);
    }
}

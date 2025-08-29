package share_data.unsynchronization;

public class SharedData {
    private int data;

    public void produce(int value) {
        data = value;
        System.out.println("Produce: " + value);
    }

    public void consume() {
        System.out.println("Consume: " + data);
    }

}

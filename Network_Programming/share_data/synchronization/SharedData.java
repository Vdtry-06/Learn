package share_data.synchronization;

public class SharedData extends Thread{
    private int data;
    // synchronized: avoid race condition : tránh tình trạng tranh chấp dữ liệu
    // does not resolve the problem of connecting Producer and Consumer
    // không giải quyết được vấn đề về giao tiếp giữa Producer và Consumer

    boolean produced = false;
    public synchronized void produce(int value) {
        if (produced) { // provide value: đã cung cấp giá trị

            // wait: the thread releases the resource and enters the waiting state
            // until another thread using the same resource calls notify().
            // wait: thread từ bỏ tài nguyên và chuyển sang trạng thái chờ (sleep/waiting)
            // cho đến khi 1 thread khác sử dụng cùng tài nguyên gọi notify().

            try {
                this.wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        data = value;
        System.out.println("Produce " + value);
        produced = true;
        notify();
    }

    // avoid race condition : tránh tình trạng tranh chấp dữ liệu
    public synchronized void consume() {
        if (!produced) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        System.out.println("Consume: " + data);
        produced = false;
        notify();
    }
}

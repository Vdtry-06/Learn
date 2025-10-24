package demo;

import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int cores = Runtime.getRuntime().availableProcessors();
        System.out.println("CPU core: " + cores);

        int mx = 20_000_000;

        int numThreads = cores;
        Thread[] threads = new Thread[numThreads];
        long[] results = new long[numThreads];

        int chunk = mx / numThreads;
        System.out.println("Chunk: " + chunk);
        long startTime = System.currentTimeMillis();

        for (int i = 0; i < numThreads; i++) {
            final int idx = i;
            final int rangeStart = i * chunk;
            final int rangeEnd = (i + 1) * chunk;
            threads[i] = new Thread(() -> {
                results[idx] = countPrimes(rangeStart, rangeEnd);
            });
            threads[i].start();
        }

        for (Thread t : threads) {
            t.join();
        }

        long totalPrimes = 0;
        for (long r : results) totalPrimes += r;

        long endTime = System.currentTimeMillis();

        System.out.println("Tổng số prime: " + totalPrimes);
        System.out.println("Thời gian chạy: " + (endTime - startTime) + " ms");
    }

    private static long countPrimes(int st, int en) {
        long cnt = 0;
        for (int i = st; i < en; i++) {
            if (isPrime(i)) cnt++;
        }
        return cnt;
    }

    private static boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

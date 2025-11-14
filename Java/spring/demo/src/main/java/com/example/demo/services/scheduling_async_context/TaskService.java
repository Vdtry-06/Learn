package com.example.demo.services.scheduling_async_context;

import org.springframework.scheduling.annotation.Async;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

@Component
public class TaskService {

    private static int cnt = 4;

    @Scheduled(fixedRate = 2000)
    public void repeatTask() {
        if (cnt == 0) return;
        System.out.println("Running scheduled task ...");
        cnt--;
    }

    @Async
    public void asyncProcess() {
        System.out.println("Running async task ...");
    }

//    @Scheduled(fixedRate = 5000)
//    public void repeatTasksV2() throws InterruptedException {
//        for (int i = 1; i <= 5; i++) {
//            asyncProcessV2(i);
//        }
//    }

    @Async("taskExecutor")
    public void asyncProcessV2(int taskId) throws InterruptedException {
        System.out.println(Thread.currentThread().getName() + " Processing task: " + taskId);
        Thread.sleep(3000); // giả sử công việc tốn thời gian
        System.out.println(Thread.currentThread().getName() + " Finished task: " + taskId);
    }
}

package com.example.demo.controllers.scheduling_async_context;

import com.example.demo.services.scheduling_async_context.TaskService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TestController {
    private final TaskService taskService;

    public TestController(TaskService taskService) {
        this.taskService = taskService;
    }

    @GetMapping("/run-multiple")
    public String runMultipleTasks() throws InterruptedException {
        for (int i = 1; i <= 20; i++) {
            taskService.asyncProcessV2(i);
        }
        return "Had sent 20 task async!";
    }
}

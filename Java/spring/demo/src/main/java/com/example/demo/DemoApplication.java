package com.example.demo;

import com.example.demo.services.application_events_context.UserService;
import com.example.demo.services.parser_standard_method_expression.ExpressionParserService;
import com.example.demo.services.language_context.Language;
import com.example.demo.services.resource_loading_context.ResourceLoadService;
import com.example.demo.services.scheduling_async_context.TaskService;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import java.io.IOException;

@SpringBootApplication
public class DemoApplication {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(DemoApplication.class, args);

        // chuyển đổi ngôn ngữ
        Language language = context.getBean(Language.class);
        language.sayHello();

        // ứng dụng sự kiện
        UserService userService = context.getBean(UserService.class);
        userService.registerUser("vdtry06");

        // đọc nội dung file
        ResourceLoadService resourceLoadService = context.getBean(ResourceLoadService.class);
        try {
            resourceLoadService.readFile("data/message.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // schedule và async
        TaskService taskService = context.getBean(TaskService.class);
        // schedule: tự động chạy theo thời gian, async: gọi mới chạy
        taskService.asyncProcess();
        // version 2
        // call api http://localhost:8080/run-multiple : run multiple task

        // spring expression
        ExpressionParserService expressionParserService = context.getBean(ExpressionParserService.class);
        expressionParserService.calculatorByExpressionParser();
        expressionParserService.calculatorByStandardEvaluationContext();
        expressionParserService.callMethod();
    }
}
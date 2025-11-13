package com.example.demo;

import com.example.demo.configs.language_context.LanguageConfig;
import com.example.demo.services.application_events_context.UserService;
import com.example.demo.services.language_context.Language;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

@SpringBootApplication
public class DemoApplication {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(DemoApplication.class, args);

        Language language = context.getBean(Language.class);
        language.sayHello();

        UserService userService = context.getBean(UserService.class);
        userService.registerUser("vdtry06");
    }
}
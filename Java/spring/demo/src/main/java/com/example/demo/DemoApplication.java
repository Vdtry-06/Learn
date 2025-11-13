package com.example.demo;

import com.example.demo.configs.language_context.LanguageConfig;
import com.example.demo.services.language_context.Language;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class DemoApplication {
    public static void main(String[] args) {
        SpringApplication.run(DemoApplication.class, args);
        LanguageConfig languageConfig = new LanguageConfig();
        Language language = new Language(languageConfig.messageSource());
        language.sayHello();
    }
}
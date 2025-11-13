package com.example.demo.services;

import org.springframework.context.MessageSource;

import java.util.Locale;

public class Language {

    private final MessageSource messageSource;

    public Language(MessageSource messageSource) {
        this.messageSource = messageSource;
    }

    public void sayHello() {
        String message_vi = messageSource.getMessage("greeting", null, Locale.forLanguageTag("vi"));
        System.out.println(message_vi);

        String message_en = messageSource.getMessage("greeting", null, Locale.forLanguageTag("en"));
        System.out.println(message_en);
    }
}

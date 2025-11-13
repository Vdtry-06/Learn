package com.example.demo.services.language_context;

import org.springframework.context.MessageSource;
import org.springframework.stereotype.Component;

import java.util.Locale;

@Component
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

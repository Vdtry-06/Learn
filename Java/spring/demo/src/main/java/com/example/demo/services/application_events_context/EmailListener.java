package com.example.demo.services.application_events_context;

import org.springframework.context.ApplicationListener;
import org.springframework.stereotype.Component;

// lắng nghe event
@Component
public class EmailListener implements ApplicationListener<UserRegisteredEvent> {

    @Override
    public void onApplicationEvent(UserRegisteredEvent event) {
        System.out.println("Send email to: " + event.getUsername());
    }

    @Override
    public boolean supportsAsyncExecution() {
        return ApplicationListener.super.supportsAsyncExecution();
    }
}

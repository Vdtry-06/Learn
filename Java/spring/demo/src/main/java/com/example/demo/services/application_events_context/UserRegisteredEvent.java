package com.example.demo.services.application_events_context;

import org.springframework.context.ApplicationEvent;

import java.time.Clock;

// tạo event
public class UserRegisteredEvent extends ApplicationEvent {
    private String username;

    public UserRegisteredEvent(Object source, String username) {
        super(source);
        this.username = username;
    }

    public String getUsername() {
        return username;
    }

    public UserRegisteredEvent(Object source, Clock clock) {
        super(source, clock);
    }


}

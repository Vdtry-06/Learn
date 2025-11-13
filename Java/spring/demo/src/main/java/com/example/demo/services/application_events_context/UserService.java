package com.example.demo.services.application_events_context;

import org.springframework.context.ApplicationEventPublisher;
import org.springframework.stereotype.Component;

// phát event
@Component
public class UserService {
    private final ApplicationEventPublisher publisher;

    public UserService(ApplicationEventPublisher publisher) {
        this.publisher = publisher;
    }

    public void registerUser(String username) {
        System.out.println("Register user: " + username);
        publisher.publishEvent(new UserRegisteredEvent(this, username));
    }
}

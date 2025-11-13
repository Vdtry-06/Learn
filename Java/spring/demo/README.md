## 1. Luồng chạy ứng dụng

### 1.1. SpringApplication.run(...) chuyện gì sẽ xảy ra ?

```commandline
Spring sẽ thực hiện 3 bước lớn:
1. Tạo Spring ApplicationContext (container)
2. Quét toàn bộ package gốc và con (component scan)
3. Tạo bean và tiêm phụ thuộc
```

```commandline
1. Nó là hộp chứa container của toàn bộ các bean trong ứng dụng
Nó chịu trách nhiệm: 
    - Tạo đối tượng bean
    - Quản lý vòng đời của bean
    - Tự động tiêm (inject) các dependency cần thiết
```

```commandline
2. Spring quét tất cả các class nằm trong cùng package (hoặc package con) của DemoApplication.class
Annotation: @SpringBootApplication thực ra là gộp của:
    @Configuration
    @ComponentScan
    @EnableAutoConfiguration

Chính @ComponentScan giúp Spring tự động quét các class có:
    @Component
    @Service
    @Repository
    @Controller
```

```commandline
3. Spring phát hiện UserService được đánh dấu @Component
=> Tự động tạo một bean UserService trong container
Vì UserService có dependency là ApplicationEventPublisher
=> Spring sẽ tự động tiêm (inject) 1 Object publisher thật từ context vào constructor
=> UserService trong Spring Container là bản đầy đủ với publisher hoạt động đúng.
```

```commandline
Ở DemoApplication:
Spring trả về chính bean UserService đã được quản lý và tiêm đầy đủ phụ thuộc.
```

```
Spring Boot khởi động
   ↓
Tạo ApplicationContext
   ↓
Quét các @Component
   ↓
Tạo bean UserService
   ↓
Inject ApplicationEventPublisher
   ↓
context.getBean(UserService.class) → trả về bản hoàn chỉnh
```
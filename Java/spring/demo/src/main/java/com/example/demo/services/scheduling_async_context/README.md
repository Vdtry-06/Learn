### Chỉ dùng @Async
```commandline
Spring sẽ tạo 1 thread pool mặc định (SimpleAsyncTaskExecutor)
Không giới hạn số lượng thread, chạy nhiều task đồng thời:
    - Tạo quá nhiều thread - Tốn RAM / CPU
    - Không kiểm soát thứ tự chạy
```

```commandline
Mở rộng cho nhiều task: dùng ThreadPoolTaskExecutor
Nếu không có ThreadPool riêng, Spring dùng default executor, không giới hạn thread
=> Dễ bị overload
```

```commandline
1. Cấu hình thread pool <AppConfig>
2. Dùng executor cho method async <appProcessV2>
3. Gọi nhiều task cùng lúc <TestController>
4. Có thể vừa lên lịch định kỳ vừa chạy bất đồng bộ <repeatTasksV2>
```
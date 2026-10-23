
```
void backtrack(/* trạng thái */) {
    
    // 1. Kiểm tra có thể cắt nhánh không
    if (/* không thể tạo ra lời giải tốt hơn */) {
        return;
    }

    // 2. Kiểm tra đã hoàn thành lời giải chưa
    if (/* điều kiện kết thúc */) {
        // Cập nhật kết quả
        return;
    }

    // 3. Thử từng lựa chọn
    for (/* từng lựa chọn */) {
        if (/* lựa chọn không hợp lệ */) {
            continue;
        }

        // 4. Chọn
        // Cập nhật trạng thái

        backtrack(/* trạng thái mới */);

        // 5. Bỏ chọn (quay lui)
        // Khôi phục trạng thái cũ
    }
}
```
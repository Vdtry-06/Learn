Scope: Phạm vi

Các loại phạm vi:
    - Global : toàn cầu
    - Code block : - Khối mã: let, const
    - Local Scope : - Hàm: var, function

- Khi gọi mỗi hàm luôn có 1 phạm vi mới được tạo
- Các hàm có thể được truy cập các biến được khai báo trong phạm vi của nó và bên ngoài nó
- Các thức 1 biến được truy cập: tìm biến ở phạm vi gần nhất
- Khi nào biến bị xóa khỏi bộ nhớ ?
    - Biến toàn cầu ? 
        khi chương trình bị thoát, web : tắt tag or f5
    - Biến trong code block & trong hàm ?
        sẽ bị xóa khỏi trong hàm & block
    - Biến trong hàm được tham chiếu bởi 1 hàm ? 
        biến đó không được xóa khỏi bộ nhớ

{
    // var: ko phải là code block nên khi khai báo var sẽ là biến global
}
.model small
.stack 100h

.data
    s db 255 dup('$')     ; Khai báo m?t m?ng char d? l?n d? ch?a chu?i nh?p vào
    cnt db 0               ; Bi?n d?m s? l?n xu?t hi?n c?a chu?i con "kmtt"
    msg db 10,13, "Enter a string: $"
    result db 10,13, "Result: $"

.code
    main proc
        mov ax, @data
        mov ds, ax

        mov ah, 09h           ; In thông báo yêu c?u nh?p chu?i
        lea dx, msg
        int 21h

        mov ah, 0Ah           ; Ð?c chu?i t? bàn phím
        lea dx, s
        int 21h

        mov ah, 09h           ; In thông báo k?t qu?
        lea dx, result
        int 21h

        mov cx, 0             ; Kh?i t?o d?m s? l?n xu?t hi?n = 0
        mov bx, 3             ; B?t d?u ki?m tra t? index 3 c?a chu?i
    check_loop:
        mov al, s[bx]         ; L?y ký t? t?i v? trí bx trong chu?i s
        cmp al, '$'           ; Ki?m tra ký t? k?t thúc chu?i
        je end_check_loop     ; N?u g?p ký t? '$', thoát kh?i vòng l?p ki?m tra

        cmp al, 't'           ; So sánh ký t? hi?n t?i có ph?i là 't' không
        jne not_matched       ; N?u không, b? qua và ki?m tra ký t? ti?p theo

        mov al, s[bx-1]       ; L?y ký t? tru?c ký t? 't'
        cmp al, 'm'           ; So sánh v?i 'm'
        jne not_matched       ; N?u không kh?p, b? qua và ki?m tra ký t? ti?p theo

        mov al, s[bx-2]       ; L?y ký t? tru?c ký t? 'm'
        cmp al, 't'           ; So sánh v?i 't'
        jne not_matched       ; N?u không kh?p, b? qua và ki?m tra ký t? ti?p theo

        mov al, s[bx-3]       ; L?y ký t? tru?c ký t? 't'
        cmp al, 'k'           ; So sánh v?i 'k'
        jne not_matched       ; N?u không kh?p, b? qua và ki?m tra ký t? ti?p theo

        inc cx                ; N?u chu?i con kh?p, tang bi?n d?m
    not_matched:
        inc bx                ; Di chuy?n t?i ký t? ti?p theo trong chu?i s
        jmp check_loop        ; L?p l?i quá trình ki?m tra

    end_check_loop:
        mov ah, 02h           ; Chu?n b? d? in ký t? xu?ng dòng
        mov dl, 0Ah           ; Ký t? xu?ng dòng
        int 21h               ; In ký t? xu?ng dòng

        mov dl, cl            ; Ð?t k?t qu? (s? l?n xu?t hi?n c?a chu?i con) vào dl d? in ra màn hình
        add dl, '0'           ; Chuy?n k?t qu? thành ký t?
        mov ah, 02h           ; Chu?n b? d? in ra màn hình
        int 21h               ; In k?t qu? ra màn hình

        mov ah, 4Ch           ; Chu?n b? d? k?t thúc chuong trình
        int 21h               ; K?t thúc chuong trình

    main endp
end main

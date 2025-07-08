.model small
.stack 100h

.data
    s db 255 dup('$')     ; Khai b�o m?t m?ng char d? l?n d? ch?a chu?i nh?p v�o
    cnt db 0               ; Bi?n d?m s? l?n xu?t hi?n c?a chu?i con "kmtt"
    msg db 10,13, "Enter a string: $"
    result db 10,13, "Result: $"

.code
    main proc
        mov ax, @data
        mov ds, ax

        mov ah, 09h           ; In th�ng b�o y�u c?u nh?p chu?i
        lea dx, msg
        int 21h

        mov ah, 0Ah           ; �?c chu?i t? b�n ph�m
        lea dx, s
        int 21h

        mov ah, 09h           ; In th�ng b�o k?t qu?
        lea dx, result
        int 21h

        mov cx, 0             ; Kh?i t?o d?m s? l?n xu?t hi?n = 0
        mov bx, 3             ; B?t d?u ki?m tra t? index 3 c?a chu?i
    check_loop:
        mov al, s[bx]         ; L?y k� t? t?i v? tr� bx trong chu?i s
        cmp al, '$'           ; Ki?m tra k� t? k?t th�c chu?i
        je end_check_loop     ; N?u g?p k� t? '$', tho�t kh?i v�ng l?p ki?m tra

        cmp al, 't'           ; So s�nh k� t? hi?n t?i c� ph?i l� 't' kh�ng
        jne not_matched       ; N?u kh�ng, b? qua v� ki?m tra k� t? ti?p theo

        mov al, s[bx-1]       ; L?y k� t? tru?c k� t? 't'
        cmp al, 'm'           ; So s�nh v?i 'm'
        jne not_matched       ; N?u kh�ng kh?p, b? qua v� ki?m tra k� t? ti?p theo

        mov al, s[bx-2]       ; L?y k� t? tru?c k� t? 'm'
        cmp al, 't'           ; So s�nh v?i 't'
        jne not_matched       ; N?u kh�ng kh?p, b? qua v� ki?m tra k� t? ti?p theo

        mov al, s[bx-3]       ; L?y k� t? tru?c k� t? 't'
        cmp al, 'k'           ; So s�nh v?i 'k'
        jne not_matched       ; N?u kh�ng kh?p, b? qua v� ki?m tra k� t? ti?p theo

        inc cx                ; N?u chu?i con kh?p, tang bi?n d?m
    not_matched:
        inc bx                ; Di chuy?n t?i k� t? ti?p theo trong chu?i s
        jmp check_loop        ; L?p l?i qu� tr�nh ki?m tra

    end_check_loop:
        mov ah, 02h           ; Chu?n b? d? in k� t? xu?ng d�ng
        mov dl, 0Ah           ; K� t? xu?ng d�ng
        int 21h               ; In k� t? xu?ng d�ng

        mov dl, cl            ; �?t k?t qu? (s? l?n xu?t hi?n c?a chu?i con) v�o dl d? in ra m�n h�nh
        add dl, '0'           ; Chuy?n k?t qu? th�nh k� t?
        mov ah, 02h           ; Chu?n b? d? in ra m�n h�nh
        int 21h               ; In k?t qu? ra m�n h�nh

        mov ah, 4Ch           ; Chu?n b? d? k?t th�c chuong tr�nh
        int 21h               ; K?t th�c chuong tr�nh

    main endp
end main

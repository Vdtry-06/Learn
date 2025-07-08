data segment
    new_line db 13, 10, "$"             ; Ky tu xuong dong
    game_draw db "_|_|_", 13, 10
              db "_|_|_", 13, 10
              db "_|_|_", 13, 10, "$"   ; Ban co tro choi
    game_pointer db 9 DUP(?)            ; Con tro bang tro choi
    win_flag db 0                       ; Co thang
    player db "0$"                      ; Nguoi choi hien tai
    game_over_message  db "FINAL RESULT", 13, 10, "$"    ; Thong bao ket thuc tro choi
    game_start_message db "WELLCOME TWO PLAYERS", 13, 10 ; Thong bao bat dau tro choi
                       db "  GAME TIC TAC TOE  ", 13, 10
                       db "      GROUP 7       ", 13, 10, "$"
    player_message     db "PLAYER $"                    ; Thong bao nguoi choi hien tai
    win_message        db " WIN!$"                      ; Thong bao thang
    draw_message       db "DRAW!$", 13, 10, "$"          ; Thong bao hoa
    type_message       db "TYPE A POSITION: $"          ; Thong bao nhap vi tri
    empty_count        db 9                             ; Dem so o trong
ends

stack segment
    dw   128  dup(?)                    ; Khoi tao ngan xep
ends

code segment
start:
    mov ax, data
    mov ds, ax                          ; Thiet lap DS thanh con tro den data segment

    call set_game_pointer               ; Thiet lap con tro bang tro choi
    jmp main_loop                       ; Bat dau vong lap chinh
      
; Vong lap chinh
main_loop:
    call clear_screen                   ; Xoa man hinh
    lea dx, game_start_message
    call print                          ; In thong bao bat dau tro choi

    lea dx, new_line
    call print                          ; In ky tu xuong dong

    lea dx, player_message
    call print                          ; In thong bao nguoi choi hien tai

    lea dx, player
    call print                          ; In nguoi choi hien tai

    lea dx, new_line
    call print                          ; In ky tu xuong dong

    lea dx, game_draw
    call print                          ; In bang tro choi

    lea dx, new_line
    call print                          ; In ky tu xuong dong

    lea dx, type_message
    call print                          ; In thong bao nhap vi tri

    call read_keyboard                  ; Doc vi tri nhap vao
    sub al, 49                          ; Chuyen ky tu so thanh so thuc
    mov bh, 0
    mov bl, al

    call update_draw                    ; Cap nhat bang tro choi

    call check                          ; Kiem tra trang thai tro choi

    cmp win_flag, 1
    je game_over                        ; Neu thang, nhay den phan ket thuc tro choi
    cmp win_flag, 2
    je game_over                        ; Neu hoa, nhay den phan ket thuc tro choi

    cmp byte ptr [empty_count], 0
    jne not_draw                        ; Neu con o trong, tiep tuc

    mov win_flag, 2                     ; Dat co hoa
    jmp game_over                       ; Nhay den phan ket thuc tro choi
       
not_draw:
    call change_player                  ; Doi nguoi choi
    jmp main_loop                       ; Quay lai vong lap chinh
 
;Ham doi luot giua 2 nguoi choi
change_player:
    lea si, player
    xor ds:[si], 1                      ; Doi nguoi choi 0 -> 1 hoac 1 -> 0
    ret

; Ham cap nhat bang tro choi sau moi nuoc di
update_draw:
    mov bl, game_pointer[bx]            ; Di chuyen gia tri cua o bang tro choi tai vi tri duoc chi dinh boi con tro bx vao thanh ghi bl
    lea si, player                      ; Lay dia chi cua bien player(bien luu tru nguoi choi hien tai) va dua no vao thanh ghi si

    cmp ds:[si], "0"                    ; So sanh ki tu tai dia chi duoc luu tru trong thanh ghi si voi ki tu "0" (dai dien nguoi choi 0)
    je draw_x                           ; Neu nguoi choi hien tai la "0" nhay den ham draw_x de ve ki tu "x" vao bang tro choi
    cmp ds:[si], "1"                    ; So sanh ki tu tai dia chi duoc luu tru trong thanh ghi si voi ki tu "1" (dai dien nguoi choi 1)
    je draw_o                           ; Neu nguoi choi hien tai la "1" nhay den ham draw_o de ve ki tu "o" vao bang tro choi

; Duoc goi khi nguoi choi hien tai la "0"
; Danh dau o trong trong bang tro choi bang ki tu "x"
draw_x:
    mov cl, "x"                         ; Di chuyen ki tu "x" vao thanh ghi  cl
    jmp update                          ; Nhay den ham update

; Duoc goi khi nguoi choi hien tai la "1" 
; Danh dau o trong trong bang tro choi bang ki tu "o"
draw_o:
    mov cl, "o"                         ; Di chuyen ki tu "o" vao thanh ghi  cl
    jmp update                          ; Nhay den ham update

; Cap nhat bang tro choi
update:
    mov ds:[bx], cl                     ; Di chuyen ki tu thanh ghi cl vao o trong trong bang tro choi duoc chi dinh boi con tro bx
    dec byte ptr [empty_count]          ; Giam so o trong
    ret

; Ham kiem tra trang thai tro choi sau moi nuoc di
check:
    call check_line                     ; Kiem tra cac hang
    call check_column                   ; Kiem tra cac cot
    call check_diagonal                 ; Kiem tra cac duong cheo
    ret
    
; Ham kiem tra cac hang cua bang tro choi    
check_line:
    mov cx, 0                           ; Khoi tao dem cx = 0 de xac dinh hang dang duoc kiem tra
    check_line_loop:                    ; Ham cho vong lap kiem tra cac hang
    ; So sanh gia tri cua cx voi cac gia tri tuong ung voi cac hang trong bang tro choi
    cmp cx, 0
    je first_line
    cmp cx, 1
    je second_line
    cmp cx, 2
    je third_line

    ret 
    
; Ham danh dau tung vi tri bat dau kiem tra cho tung hang tuong ung

first_line:
    mov si, 0                           
    jmp do_check_line

second_line:
    mov si, 3
    jmp do_check_line

third_line:
    mov si, 6
    jmp do_check_line

; Ham kiem tra cac o trong hang cua bang tro choi
do_check_line:
    inc cx                              ; Tang cx len 1 de chuyen sang kiem tra hang tiep theo
    mov bh, 0                           ; Dat bh = 0
    mov bl, game_pointer[si]            ; bl = gia tri cua o bang tro choi tai vi tri hien tai
    mov al, ds:[bx]                     ; Di chuyen gia tri cua o bang tro choi vao thanh ghi al
    cmp al, "_"                         ; So sanh gia tri cua o bang tro choi voi ki tu "_" de kiem tra xem o do co duoc dien hay khong
    je check_line_loop                  ; Neu o trong, nhay den ham check_line_loop de tiep tuc kiem tra cac o tiep theo trong hang

    inc si                              ; Di chuyen den o tiep theo trong hang
    mov bl, game_pointer[si]            ; bl = gia tri cua o bang tro choi tai vi tri hien tai
    cmp al, ds:[bx]                     ; So sanh ki tu cua o do co giong voi o dau tien hay khong
    jne check_line_loop                 ; Neu khong, nhay den check_line_loop de tiep tuc kiem tra hang
    
    ; Tuong tu 4 dong code tren
    inc si                              
    mov bl, game_pointer[si]            
    cmp al, ds:[bx]                    
    jne check_line_loop                 

    mov win_flag, 1                     ; Neu tat ca cac o trong hang deu giong nhau va khong phai o trong, dat co chien thang thang 1
    ret                                 ; Ket thuc ham
    
; Ham kiem tra cac cot cua bang tro choi
check_column:
    mov cx, 0                           ; Khoi tao dem cx = 0 de xac dinh cot dang duoc kiem tra
    check_column_loop:                  ; Ham cho vong lap kiem tra cac cot
    ; So sanh gia tri cua cx voi cac gia tri tuong ung voi cac cot trong bang tro choi
    ; Neu cx trung voi gia tri cua cot, nhay den ham tuong ung de bat dau kiem tra cot do
    cmp cx, 0
    je first_column
    cmp cx, 1
    je second_column
    cmp cx, 2
    je third_column

    ret

;Ham danh dau cac vi tri bat dau kiem tra cho tung cot tuong ung

first_column:
    mov si, 0
    jmp do_check_column

second_column:
    mov si, 1
    jmp do_check_column

third_column:
    mov si, 2
    jmp do_check_column

; Ham kiem tra cac o trong cot cua bang tro choi
do_check_column:
    inc cx                              ; Tang cx len 1 de chuyen sang kiem tra cot tiep theo
    mov bh, 0                           ; Dat bh = 0
    mov bl, game_pointer[si]            ; bl = gia tri cua o bang tro choi tai vi tri hien tai
    mov al, ds:[bx]                     ; Di chuyen gia tri cua o bang tro choi vao thanh ghi al
    cmp al, "_"                         ; So sanh gia tri cua o bang tro choi voi ki tu "_" de kiem tra o do co duoc kiem tra khong
    je check_column_loop                ; Neu o trong, nhay den ham check_column_loop de tiep tuc kiem tra o tiep theo trong hang
    
    add si, 3                           ; Di chuyen den o tiep theo trong cot (vi cac o trong 1 cot cach nhay 3 vi tri trong bo nho)
    mov bl, game_pointer[si]            ; Di chuyen gia tri cua o bang tro choi vao bl 
    cmp al, ds:[bx]                     ; So sanh gia tri cua o do voi o dau tien trong cot
    jne check_column_loop               ; Neu khong giong nhau, nhay den check_column_loop de kiem tra cot khac
    
    ; Tuong tu 4 dong code tren
    add si, 3
    mov bl, game_pointer[si]
    cmp al, ds:[bx]
    jne check_column_loop

    mov win_flag, 1                     ; Neu tat ca cac o trong cot deu giong nhay va khong phai o trong, dat co chien thang thanh 1
    ret                                 ; Ket thuc ham

; Ham kiem tra cac duong cheo cua bang tro choi
check_diagonal:
    mov cx, 0                           ; Khoi tao bien dem cx voi gia tri 0 de su dung trong viec xac dinh duong cheo nao dang duoc kiem tra
    check_diagonal_loop:                ; Ham cho vong lap kiem tra cac duong cheo
    cmp cx, 0                           ; So sanh cx voi 0
    je first_diagonal                   ; Neu bang 0, nhay den nhan first_diagonal de kiem tra duong cheo chinh (tu tren cung ben trai den duoi cung ben phai)
    cmp cx, 1                           ; So sanh cx voi 1
    je second_diagonal                  ; Neu bang 1, nhay den nhan second_diagonal de kiem tra duong cheo phu (tu tren cung ben phai den duoi cung ben trai)

    ret                                 ; Neu cx khong bang 0 hoac 1, ket thuc ham va tra ve

; Ham de bat dau kiem tra duong cheo chinh
first_diagonal:
    mov si, 0                           ; Khoi tao si voi gia tri 0, tuong ung voi vi tri dau tien cua duong cheo chinh
    mov dx, 4                           ; Khoi tao dx voi gia tri 4, tuong ung voi khoang cach giua cac o lien tiep trong duong cheo chinh
    jmp do_check_diagonal               ; Nhay den nhan do_check_diagonal de bat dau qua trinh kiem tra

; Ham de bat dau kiem tra duong cheo phu
second_diagonal:
    mov si, 2                           ; Khoi tao si voi gia tri 2, tuong ung voi vi tri dau tien cua duong cheo phu
    mov dx, 2                           ; Khoi tao dx voi gia tri 2, tuong ung voi khoang cach giua cac o lien tiep trong duong cheo phu
    jmp do_check_diagonal               ; Nhay den nhan do_check_diagonal de bat dau qua trinh kiem tra

; Ham de thuc hien kiem tra cac o trong duong cheo
do_check_diagonal:
    inc cx                              ; Tang gia tri cua cx len 1 de chuyen sang kiem tra duong cheo tiep theo trong lan lap sau
    mov bh, 0                           ; Dat bh bang 0 
    mov bl, game_pointer[si]            ; bl = gia tri cua con tro bang tro choi tai vi tri si
    mov al, ds:[bx]                     ; Di chuyen gia tri cua o bang tro choi tai vi tri bx vao thanh ghi al
    cmp al, "_"                         ; So sanh gia tri cua o voi ky tu "_" de kiem tra xem o do co trong khong
    je check_diagonal_loop              ; Neu trong, nhay den check_diagonal_loop de tiep tuc kiem tra duong cheo tiep theo

    add si, dx                          ; Cong si voi dx de di chuyen den o tiep theo trong duong cheo
    mov bl, game_pointer[si]            ; Di chuyen gia tri cua o bang tro choi tai vi tri bx vao bl
    cmp al, ds:[bx]                     ; So sanh gia tri cua o do voi gia tri ban dau trong al
    jne check_diagonal_loop             ; Neu khong khop, nhay den check_diagonal_loop de tiep tuc kiem tra duong cheo tiep theo
    
    ; Tuong tu 4 dong code tren
    add si, dx
    mov bl, game_pointer[si]
    cmp al, ds:[bx]
    jne check_diagonal_loop

    mov win_flag, 1                     ; Neu tat ca cac o trong duong cheo deu giong nhau va khong phai la o trong, dat co chien thang thanh 1
    ret                                 ; Ket thuc ham

; Ham hien thi thong bao va ket qua tren man hinh
game_over:
    ; Goi cac ham va dia chi de in ra ket qua va ket thuc chuong trinh
    call clear_screen
    lea dx, game_start_message
    call print

    lea dx, new_line
    call print

    lea dx, game_draw
    call print

    lea dx, new_line
    call print

    lea dx, game_over_message
    call print

    cmp win_flag, 1
    je print_winner

    cmp win_flag, 2
    je print_draw

    jmp fim

; Ham in ra thong diep nguoi chien thang
print_winner:
    lea dx, player_message
    call print

    lea dx, player
    call print

    lea dx, win_message
    call print

    jmp fim

; Ham in thong diep hoa
print_draw:
    lea dx, draw_message
    call print

    jmp fim
   
; Ham thiet lap con tro den bang tro choi   
set_game_pointer:
    lea si, game_draw
    lea bx, game_pointer
    mov cx, 9
    loop_1:
    cmp cx, 6
    je add_1
    cmp cx, 3
    je add_1
    jmp add_2

add_1:
    add si, 1

add_2:
    mov ds:[bx], si
    add si, 2
    inc bx
    loop loop_1
    ret

; Ham in chuoi ra man hinh o vi tri hien tai
print:
    mov ah, 9
    int 21h
    ret
; Ham xoa man hinh
clear_screen:
    mov ah, 0fh
    int 10h
    mov ah, 0
    int 10h
    ret
; Ham doc phim tu ban phim
read_keyboard:
    mov ah, 1
    int 21h
    ret

fim: 
    ; Danh dau ket thuc chuong trinh
    jmp fim 

code ends

end start

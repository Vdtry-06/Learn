data segment                            ; Khai bao doan du lieu    
    new_line db 13, 10, "$"             ; Ki tu xuong dong
                                        
    game_draw db "_|_|_", 13, 10        ; Bien luu trang thai ban dau cua bang tro choi
              db "_|_|_", 13, 10
              db "_|_|_", 13, 10, "$"   
                  
    game_pointer db 9 DUP(?)            ; Mang de tro toi vi tri trong bang tro choi
    
    win_flag db 0                       ; Ham kiem tra nguoi thang cuoc
    player db "0$"                      ; Bien luu nguoi choi hien tai (0 hoac 1)
    
    game_over_message db "FINAL RESULT", 13, 10, "$"                            ; Thong bao ket thuc tro choi   
    game_start_message db "GROUP 7 (TIC TAC TOE) BY EIGHT MEMBER", 13, 10, "$"
    player_message db "PLAYER $"                                                ; Thong bao nguoi choi hien tai
    win_message db " WIN!$"                                                     ; Thong bao nguoi choi chien thang
    draw_message db "FINAL RESULT", 13, 10, "DRAW$", 13, 10, "$"                ; Thong bao ket qua hoa
    type_message db "TYPE A POSITION: $"                                        ; Thong bao yeu cau nguoi choi nhap vi tri
    empty_count db 9                                                            ; dem so o trong con lai
ends

stack segment
    dw   128  dup(?)                    ; Khoi tao ngan xep voi 128 tu
ends         

extra segment
    
ends

code segment
start:
    ; Thiet lap cac thanh ghi doan
    mov     ax, data
    mov     ds, ax
    mov     ax, extra
    mov     es, ax

    ; Bat dau tro choi
    call    set_game_pointer            ; Goi ham thiet lap con tro tro choi
            
main_loop:  
    call    clear_screen                ; Goi ham xoa man hinh
    
    lea     dx, game_start_message 
    call    print                       ; In thong bao bat dau tro choi
    
    lea     dx, new_line
    call    print                       ; In dong moi
    
    lea     dx, player_message
    call    print                       ; In thong bao nguoi choi
                                        
    lea     dx, player
    call    print                       ; In nguoi choi hien tai
    
    lea     dx, new_line
    call    print                       ; In dong moi
    
    lea     dx, game_draw
    call    print                    ;??? In bang tro choi hien tai
    
    lea     dx, new_line
    call    print                       ; In dong moi
    
    lea     dx, type_message    
    call    print                       ; In thong bao yeu cau nguoi choi nhap vi tri
                        
                                          
    call    read_keyboard               ; Doc vi tri nguoi choi nhap
                       
    ;??? Tinh toan vi tri hoa                  
    sub     al, 49                      ; Chuyen ki tu so thanh so thuc             
    mov     bh, 0
    mov     bl, al                                  
                                  
    call    update_draw              ;??? Cap nhat bang tro choi voi vi tri moi                   
                                                          
    call    check                       ; Kiem tra trang thai tro choi
    
    ; Kiem tra neu tro choi ket thuc                   
    cmp     win_flag, 1  
    je      game_over                   ; Neu co nguoi thang nhay toi phan ket thuc tro choi
    cmp     win_flag, 2  
    je      game_over_draw              ; Neu hoa, nhay toi phan ket thuc tro choi hoa
    
    ; Kiem tra hoa
    cmp     byte ptr [empty_count], 0
    jne     not_draw                    ; Neu con o trong thi tiep tuc thuc hien
    
    ; Ket thuc tro choi voi ket qua hoa
    jmp     game_over_draw

not_draw:
    call    change_player               ; Doi nguoi choi
            
    jmp     main_loop                   ; Quay lai vong lap chinh

change_player:   
    lea     si, player    
    xor     ds:[si], 1                  ; Doi nguoi choi 0 -> 1 hoac 1 -> 0
    
    ret
      
 
update_draw:
    mov     bl, game_pointer[bx]
    mov     bh, 0
    
    lea     si, player
    
    cmp     ds:[si], "0"                
    je      draw_x                      ; Neu la nguoi choi 0, ve X
                  
    cmp     ds:[si], "1"
    je      draw_o                      ; Neu la nguoi choi 1, ve O
                  
    draw_x:
    mov     cl, "x"
    jmp     update

    draw_o:          
    mov     cl, "o"  
    jmp     update    
          
    update:         
    mov     ds:[bx], cl                 ; Cap nhat vi tri voi X hoac O
    dec     byte ptr [empty_count]      ; Giam so o trong
      
    ret 
       
       
check:
    call    check_line                  ; Goi ham kiem tra cac dong
    ret     
       
       
check_line:
    mov     cx, 0
    
    check_line_loop:     
    cmp     cx, 0
    je      first_line                  ; Kiem tra dong dau tien
    
    cmp     cx, 1
    je      second_line                 ; Kiem tra dong thu 2
    
    cmp     cx, 2
    je      third_line                  ; Kiem tra dong thu 3
    
    call    check_column                ; Goi ham kiem tra cac cot
    ret    
        
    first_line:    
    mov     si, 0   
    jmp     do_check_line               ; Nhay toi phan kiem tra dong

    second_line:    
    mov     si, 3
    jmp     do_check_line
    
    third_line:    
    mov     si, 6
    jmp     do_check_line        

    do_check_line:
    inc     cx
  
    mov     bh, 0
    mov     bl, game_pointer[si]
    mov     al, ds:[bx]
    cmp     al, "_"
    je      check_line_loop             ; Neu o trong, tiep tuc vong lap kiem tra
    
    inc     si
    mov     bl, game_pointer[si]    
    cmp     al, ds:[bx]
    jne     check_line_loop             ; Neu khong giong nhau, tiep tuc vong lap kiem tra
      
    inc     si
    mov     bl, game_pointer[si]  
    cmp     al, ds:[bx]
    jne     check_line_loop             ; Neu khong giong nhau tiep tuc vong lap kiem tra
                 
                         
    mov     win_flag, 1                 ; Dat co thang
    ret         
       
       
       
check_column:
    mov     cx, 0
    
    check_column_loop:     
    cmp     cx, 0
    je      first_column                ; Kiem tra cot dau tien
    
    cmp     cx, 1
    je      second_column               ; Kiem tra cot thu 2
    
    cmp     cx, 2
    je      third_column                ; Kiem tra cot thu 3
    
    call    check_diagonal              ; Goi ham kiem tra cac duong cheo
    ret    
        
    first_column:    
    mov     si, 0                       ; Nhay toi phan kiem tra cot
    jmp     do_check_column   

    second_column:    
    mov     si, 1
    jmp     do_check_column
    
    third_column:    
    mov     si, 2
    jmp     do_check_column        

    do_check_column:
    inc     cx
  
    mov     bh, 0
    mov     bl, game_pointer[si]
    mov     al, ds:[bx]
    cmp     al, "_"
    je      check_column_loop           ; Neu o trong, tiep tuc vong lap kiem tra
    
    add     si, 3
    mov     bl, game_pointer[si]    
    cmp     al, ds:[bx]
    jne     check_column_loop           ; Neu khong giong nhau, tiep tuc vong lap kiem tra
      
    add     si, 3
    mov     bl, game_pointer[si]  
    cmp     al, ds:[bx]
    jne     check_column_loop           ; Neu khong giong nhau, tiep tuc vong lap kiem tra
                 
                         
    mov     win_flag, 1                 ; Dat co thang
    ret        


check_diagonal:
    mov     cx, 0
    
    check_diagonal_loop:     
    cmp     cx, 0
    je      first_diagonal              ; Kiem tra duong cheo dau tien
    
    cmp     cx, 1
    je      second_diagonal             ; Kiem tra duong cheo thu 2            
    
    ret    
        
    first_diagonal:    
    mov     si, 0                
    mov     dx, 4           
    jmp     do_check_diagonal           ; Nhay toi phan kiem tra duong cheo

    second_diagonal:    
    mov     si, 2
    mov     dx, 2
    jmp     do_check_diagonal       

    do_check_diagonal:
    inc     cx
  
    mov     bh, 0
    mov     bl, game_pointer[si]
    mov     al, ds:[bx]
    cmp     al, "_"
    je      check_diagonal_loop         ; Neu o trong tiep tuc vong lap kiem tra
    
    add     si, dx
    mov     bl, game_pointer[si]    
    cmp     al, ds:[bx]
    jne     check_diagonal_loop         ; Neu khong giong nhau, tiep tuc vong lap kiem tra
      
    add     si, dx
    mov     bl, game_pointer[si]  
    cmp     al, ds:[bx]
    jne     check_diagonal_loop         ; Neu khong giong nhau, tiep tuc vong lap kiem tra
                 
                         
    mov     win_flag, 1                 ; Dat co thang
    ret  
           

game_over:        
    call    clear_screen                ; Goi ham xoa man hinh
    
    lea     dx, game_start_message 
    call    print                       ; In thong bao bat dau tro choi
    
    lea     dx, new_line
    call    print                       ; In dong moi   
    
    lea     dx, game_draw
    call    print                    ;??? In bang tro choi hien tai
    
    lea     dx, new_line
    call    print                       ; In dong moi

    lea     dx, game_over_message
    call    print                       ; In thong bao ket thuc tro choi
    
    lea     dx, player_message
    call    print                       ; In thong bao nguoi choi
    
    lea     dx, player
    call    print                       ; In nguoi choi hien tai
    
    lea     dx, win_message
    call    print                       ; In thong bao nguoi choi thang

    jmp     fim                         ; Nhay toi phan ket thuc chuong trinh

game_over_draw:
    call    clear_screen                ; Goi ham xoa man hinh
    
    lea     dx, game_start_message       
    call    print                       ; In thong bao bat dau tro choi
    
    lea     dx, new_line
    call    print                       ; In dong moi   
    
    lea     dx, game_draw
    call    print                       ; In bang tro choi hien tai
    
    lea     dx, new_line
    call    print                       ; In dong moi
    

    lea     dx, draw_message
    call    print                       ; In thong bao ket qua hoa

    jmp     fim   
  
     
set_game_pointer:
    lea     si, game_draw
    lea     bx, game_pointer          
              
    mov     cx, 9   
    
    loop_1:
    cmp     cx, 6
    je      add_1                
    
    cmp     cx, 3
    je      add_1
    
    jmp     add_2 
    
    add_1:
    add     si, 1
    jmp     add_2     
      
    add_2:                                
    mov     ds:[bx], si 
    add     si, 2
                        
    inc     bx                          
    loop    loop_1                      ; Vong lap thiet lap con tro tro choi
 
    ret  
         
       
print:                                  ; In noi dung dx  
    mov     ah, 9                       ; Goi ngat de in
    int     21h   
    
    ret 
    

clear_screen:                           ; Lay va thiet lap che do video
    mov     ah, 0fh
    int     10h                         ; Lay che do video hien tai
    
    mov     ah, 0
    int     10h                         ; Thiet lap che do video
    
    ret
       
    
read_keyboard:                          ; Doc ban phim va tra ve noi dung trong ah
    mov     ah, 1       
    int     21h                         ; Goi ngat de doc ban phim
    
    ret      
      
      
fim:
    jmp     fim                         ; Vong lap vo han de ket thuc chuong trinh
      
code ends

end start
                                        ; Ket thuc doan ma va chi ra diem bat dau cua chuong trinh
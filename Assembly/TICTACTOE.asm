Data Segment
    
    New_Line db 13, 10, "$"             ; Ky tu xuong Dong
    
    Board_Game db "_|_|_", 13, 10       ; Ban co tro choi
               db "_|_|_", 13, 10       
               db "_|_|_", 13, 10, "$"
                 
    Game_Array db 9 DUP(?)              ; Mang luu tru dia chi cua cac o trong bang tro choi co caro
    Win_Flag db 0                       ; Co thang
    Player db "0$"                      ; Nguoi choi hien tai
    
    Game_Start_Message db "WELLCOME TWO PLAYERS", 13, 10 ; Thong bao bat dau tro choi
                       db "  GAME TIC TAC TOE  ", 13, 10
                       db "      GROUP 7       ", 13, 10, "$"                   
    Game_Over_Message  db "FINAL RESULT", 13, 10, "$"    ; Thong bao ket thuc tro choi 
    
    Player_Message     db "PLAYER $"                     ; Thong bao nguoi choi hien tai
    Win_Message        db " WIN!$"                       ; Thong bao thang
    Draw_Message       db "DRAW!$", 13, 10, "$"          ; Thong bao hoa
    Type_Message       db "TYPE A POSITION: $"           ; Thong bao nhap vi tri
    Empty_Count        db 9                              ; Dem so o trong
    
Ends

Stack Segment
    dw   128  dup(?)                    ; Khoi tao ngan xep
    
Ends

Code Segment
    
Start:
    mov ax, Data
    mov ds, ax                          ; Thiet lap ds thanh con tro den Data Segment

    call Set_Game_Array                 ; Thiet lap mang luu tru dia chi bang tro choi
    jmp Main_Loop                       ; Bat dau vong lap chinh 
    
    
    
    
    
    
    
     
; VONG LAP CHINH
Main_Loop:
    call Clear_Screen                   ; Xoa man hinh
    lea dx, Game_Start_Message
    call Print                          ; In thong bao bat dau tro choi

    lea dx, New_Line
    call Print                          ; In ky tu xuong Dong

    lea dx, Player_Message
    call Print                          ; In thong bao nguoi choi hien tai

    lea dx, Player
    call Print                          ; In nguoi choi hien tai

    lea dx, New_Line
    call Print                          ; In ky tu xuong Dong

    lea dx, Board_Game
    call Print                          ; In bang tro choi

    lea dx, New_Line
    call Print                          ; In ky tu xuong Dong

    lea dx, Type_Message
    call Print                          ; In thong bao nhap vi tri

    call Read_keyboard                  ; Doc vi tri nhap vao
    sub al, 49                          ; Chuyen ky tu so thanh so thuc
    mov bh, 0
    mov bl, al

    call Update_Board                   ; Cap nhat bang tro choi

    call Check                          ; Kiem tra trang thai tro choi

    cmp Win_Flag, 1
    je Game_Over                        ; Neu thang, nhay den phan ket thuc tro choi
    cmp Win_Flag, 2
    je Game_Over                        ; Neu hoa, nhay den phan ket thuc tro choi

    cmp byte ptr [Empty_Count], 0
    jne Not_Draw                        ; Neu con o trong, tiep tuc

    mov Win_Flag, 2                     ; Dat co hoa
    jmp Game_Over                       ; Nhay den phan ket thuc tro choi


              
              
 
 
 
 
; HAM TIEP TUC LUOT CHOI KHI TRO CHOI CHUA ROI VAO TRUONG HOP HOA       
Not_Draw:
    call Change_Player                  ; Doi nguoi choi
    jmp Main_Loop                       ; Quay lai vong lap chinh

 
 
 
; HAM DOI LUOT GIUA 2 NGUOI CHOI
Change_Player:
    lea si, Player
    xor ds:[si], 1                      ; Doi nguoi choi 0 -> 1 hoac 1 -> 0
    ret
     

; HAM CAP NHAT BANG TRO CHOI SAU MOI NUOC DI
Update_Board:
    mov bl, Game_Array[bx]              ; Di chuyen gia tri cua o bang tro choi tai vi tri duoc chi dinh boi con tro bx vao thanh ghi bl
    lea si, Player                      ; Lay dia chi cua bien Player(bien luu tru nguoi choi hien tai) va dua no vao thanh ghi si

    cmp ds:[si], "0"                    ; So sanh ki tu tai dia chi duoc luu tru trong thanh ghi si voi ki tu "0" (dai dien nguoi choi 0)
    je Tick_x                           ; Neu nguoi choi hien tai la "0" nhay den ham Tick_x de danh dau ki tu "x" vao bang tro choi
    cmp ds:[si], "1"                    ; So sanh ki tu tai dia chi duoc luu tru trong thanh ghi si voi ki tu "1" (dai dien nguoi choi 1)
    je Tick_o                           ; Neu nguoi choi hien tai la "1" nhay den ham Tick_o de danh dau ki tu "o" vao bang tro choi
  
   
; Khi nguoi choi hien tai la 0
Tick_x:
    mov cl, "x"                         ; Di chuyen ki tu "x" vao thanh ghi  cl
    jmp Update                          ; Nhay den ham Update


; Khi nguoi choi hien tai la 1
Tick_o:
    mov cl, "o"                         ; Di chuyen ki tu "o" vao thanh ghi  cl
    jmp Update                          ; Nhay den ham Update


; Cap nhat bang tro choi
Update:
    mov ds:[bx], cl                     ; Di chuyen ki tu thanh ghi cl vao o trong trong bang tro choi duoc chi dinh boi con tro bx
    dec byte ptr [Empty_Count]          ; Giam so o trong
    ret


; HAM KIEM TRA TRANG THAI TRO CHOI SAU MOI NUOC DI
Check:
    call Check_Row                      ; Kiem tra cac hang
    call Check_Column                   ; Kiem tra cac cot
    call Check_Diagonal                 ; Kiem tra cac duong cheo
    ret

 
 
 
 
 
 
    
; HAM KHOI TAO QUA TRINH KIEM TRA CAC HANG TREN BANG    
Check_Row:
    mov cx, 0                           ; Khoi tao dem cx = 0 de xac dinh hang dang duoc kiem tra
    Check_Row_Loop:                     ; Ham cho vong lap kiem tra cac hang
    ; So sanh gia tri cua cx voi cac gia tri tuong ung voi cac hang trong bang tro choi
    cmp cx, 0
    je First_Row
    cmp cx, 1
    je Second_Row
    cmp cx, 2
    je Third_Row
    ret 
   
First_Row:                              ; Nhan xac dinh vi tri bat dau cua hang 0
    mov si, 0                           ; Nhay den hang Do_Check_Row de kiem tra hang do
    jmp Do_Check_Row

Second_Row:                             ; Nhan xac dinh vi tri bat dau cua hang 1
    mov si, 3                           ; Nhay den hang Do_Check_Row de kiem tra hang do
    jmp Do_Check_Row

Third_Row:                              ; Nhan xac dinh vi tri bat dau cua hang 2
    mov si, 6                           ; Nhay den hang Do_Check_Row de kiem tra hang do
    jmp Do_Check_Row


; HAM KIEM TRA CAC O TRONG HANG DA XAC DINH
Do_Check_Row:

    ;////////////////////////////////EXPLAIN Do_Check_Row////////////////////////////// 
    ;/                                                                                /
    ;/ Su dung bien cx de theo doi hang hien tai                                      /
    ;/ Di chuyen qua tung o trong hang va so sanh gia tri cua o do voi o dau tien     /
    ;/ Neu tat ca cac o trong hang deu giong nhau va khong trong "_"                  /
    ;/ => co Win_Flag = 1: chi ra co nguoi choi da chien thang trong hang do          /
    ;/ Neu co bat ki o nao trong hoac khong giong nhau                                /
    ;/ => qua trinh kiem tra ket thuc va khong co nguoi chien thang nao duoc xac dinh /
    ;/                                                                                /
    ;//////////////////////////////////////////////////////////////////////////////////
     
    inc cx                              ; Tang cx len 1 de chuyen sang kiem tra hang tiep theo 
    mov bh, 0                           ; Dat bh = 0
    mov bl, Game_Array[si]              ; bl = gia tri cua o bang tro choi tai vi tri hien tai
    mov al, ds:[bx]                     ; Di chuyen gia tri cua o bang tro choi vao thanh ghi al
    cmp al, "_"                         ; So sanh gia tri cua o bang tro choi voi ki tu "_" de kiem tra xem o Do co duoc dien hay khong
    je Check_Row_Loop                   ; Neu o trong, nhay den ham Check_Row_Loop de tiep tuc kiem tra cac o tiep theo trong hang

    inc si                              ; Di chuyen den o tiep theo trong hang
    mov bl, Game_Array[si]              ; bl = gia tri cua o bang tro choi tai vi tri hien tai
    cmp al, ds:[bx]                     ; So sanh ki tu cua o Do co giong voi o dau tien hay khong
    jne Check_Row_Loop                  ; Neu khong, nhay den Check_Row_Loop de tiep tuc kiem tra hang
    
    ; Tuong tu 4 Dong Code tren
    inc si                              
    mov bl, Game_Array[si]            
    cmp al, ds:[bx]                    
    jne Check_Row_Loop                 

    mov Win_Flag, 1                     ; Neu tat ca cac o trong hang deu giong nhau va khong phai o trong, dat co chien thang thang 1
    ret                                 ; Ket thuc ham
 
 
 
 
 
 
 
 
 
    
; HAM KHOI TAO QUA TRINH KIEM TRA CAC COT TREN BANG
Check_Column:
    mov cx, 0                           ; Khoi tao dem cx = 0 de xac dinh cot dang duoc kiem tra
    Check_Column_Loop:                  ; Ham cho vong lap kiem tra cac cot
    ; So sanh gia tri cua cx voi cac gia tri tuong ung voi cac cot trong bang tro choi
    ; Neu cx trung voi gia tri cua cot, nhay den ham tuong ung de bat dau kiem tra cot Do
    cmp cx, 0
    je First_Column
    cmp cx, 1
    je Second_Column
    cmp cx, 2
    je Third_Column
    ret

First_Column:                           
    mov si, 0                           ; Nhan xac dinh vi tri bat dau cua cot 0
    jmp Do_Check_Column                 ; Nhay den hang Do_Check_Column de kiem tra cot do

Second_Column:
    mov si, 1                           ; Nhan xac dinh vi tri bat dau cua cot 1
    jmp Do_Check_Column                 ; Nhay den hang Do_Check_Column de kiem tra cot do

Third_Column:
    mov si, 2                           ; Nhan xac dinh vi tri bat dau cua cot 2
    jmp Do_Check_Column                 ; Nhay den hang Do_Check_Column de kiem tra cot do


; HAM KIEM TRA CAC O TRONG COT DA XAC DINH
Do_Check_Column:
    
    ;////////////////////////////////EXPLAIN Do_Check_Column//////////////////////////////
    ;/                                                                                   /
    ;/ Su dung bien cx de theo doi cot hien tai                                          /
    ;/ Di chuyen qua tung o trong cot va so sanh gia tri cua o do voi o dau tien cua cot /
    ;/ Neu tat ca cac o trong cot deu giong nhau va khong trong "_"                      /
    ;/ => co Win_Flag = 1 chi ra rang co nguoi chien thang trong cot do                  /
    ;/ Neu co bat ky o nao trong hoac khong giong nhau                                   /
    ;/ => qua trinh kiem tra se ket thuc va khong co nguoi chien thang nao duoc xac dinh / 
    ;/                                                                                   /
    ;/////////////////////////////////////////////////////////////////////////////////////
    
    inc cx                              ; Tang cx len 1 de chuyen sang kiem tra cot tiep theo
    mov bh, 0                           ; Dat bh = 0
    mov bl, Game_Array[si]              ; bl = gia tri cua o bang tro choi tai vi tri hien tai
    mov al, ds:[bx]                     ; Di chuyen gia tri cua o bang tro choi vao thanh ghi al
    cmp al, "_"                         ; So sanh gia tri cua o bang tro choi voi ki tu "_" de kiem tra o Do co duoc kiem tra khong
    je Check_Column_Loop                ; Neu o trong, nhay den ham Check_Column_Loop de tiep tuc kiem tra o tiep theo trong hang
    
    add si, 3                           ; Di chuyen den o tiep theo trong cot (vi cac o trong 1 cot cach nhay 3 vi tri trong bo nho)
    mov bl, Game_Array[si]              ; Di chuyen gia tri cua o bang tro choi vao bl 
    cmp al, ds:[bx]                     ; So sanh gia tri cua o Do voi o dau tien trong cot
    jne Check_Column_Loop               ; Neu khong giong nhau, nhay den Check_Column_Loop de kiem tra cot khac
    
    ; Tuong tu 4 Dong Code tren
    add si, 3
    mov bl, Game_Array[si]
    cmp al, ds:[bx]
    jne Check_Column_Loop

    mov Win_Flag, 1                     ; Neu tat ca cac o trong cot deu giong nhay va khong phai o trong, dat co chien thang thanh 1
    ret                                 ; Ket thuc ham



  
  
  
  
  
  
  
  

; HAM KHOI TAO QUA TRINH KIEM TRA CAC DUONG CHEO TREN BANG
Check_Diagonal: 
    ; su dung bien cx de xac dinh loai duong cheo dang duoc kiem tra
    mov cx, 0                           ; Khoi tao bien dem cx voi gia tri 0 de su dung trong viec xac dinh duong cheo nao dang duoc kiem tra
    Check_Diagonal_Loop:                ; Ham cho vong lap kiem tra cac duong cheo
    cmp cx, 0                           ; So sanh cx voi 0
    je First_Diagonal                   ; Neu bang 0, nhay den nhan First_Diagonal de kiem tra duong cheo chinh 
    cmp cx, 1                           ; So sanh cx voi 1
    je Second_Diagonal                  ; Neu bang 1, nhay den nhan Second_Diagonal de kiem tra duong cheo phu 
    ret                                 ; Neu cx khong bang 0 hoac 1, ket thuc ham va tra ve


; Nhan kiem tra duong cheo chinh
First_Diagonal:
    mov si, 0                           ; Khoi tao si voi gia tri 0, tuong ung voi vi tri dau tien cua duong cheo chinh
    mov dx, 4                           ; Khoi tao dx voi gia tri 4, tuong ung voi khoang cach giua cac o lien tiep trong duong cheo chinh
    jmp Do_Check_Diagonal               ; Nhay den nhan Do_Check_Diagonal de bat dau qua trinh kiem tra

; Nhan kiem tra duong cheo phu
Second_Diagonal:
    mov si, 2                           ; Khoi tao si voi gia tri 2, tuong ung voi vi tri dau tien cua duong cheo phu
    mov dx, 2                           ; Khoi tao dx voi gia tri 2, tuong ung voi khoang cach giua cac o lien tiep trong duong cheo phu
    jmp Do_Check_Diagonal               ; Nhay den nhan Do_Check_Diagonal de bat dau qua trinh kiem tra


; Ham de thuc hien kiem tra cac o tren duong cheo da duoc xac dinh
Do_Check_Diagonal:
 
    ;/////////////////////////////////////EXPLAIN Do_Check_Diagonal////////////////////////////////////// 
    ;/                                                                                                  /
    ;/ Su dung bien cx de theo doi duong cheo hien tai                                                  /
    ;/ Di chuyen qua tung o tren duong cheo va so sanh gia tri cua o do voi o dau tien tren duong cheo  /
    ;/ Neu tat ca cac o tren duong cheo deu giong nhau va khong trong "_"                               /
    ;/ => co Win_Flag = 1, chi ra rang co nguoi choi da thang tren duong cheo do                        /
    ;/ Neu co bat ki o nao trong hoac khong giong nhau                                                  /
    ;/ => qua trinh kiem tra ket thuc va khong co nguoi chien thang nao duoc xac dinh                   /
    ;/                                                                                                  /
    ;////////////////////////////////////////////////////////////////////////////////////////////////////
    
    inc cx                              ; Tang gia tri cua cx len 1 de chuyen sang kiem tra duong cheo tiep theo trong lan lap sau
    mov bh, 0                           ; Dat bh bang 0 
    mov bl, Game_Array[si]              ; bl = gia tri cua con tro bang tro choi tai vi tri si
    mov al, ds:[bx]                     ; Di chuyen gia tri cua o bang tro choi tai vi tri bx vao thanh ghi al
    cmp al, "_"                         ; So sanh gia tri cua o voi ky tu "_" de kiem tra xem o Do co trong khong
    je Check_Diagonal_Loop              ; Neu trong, nhay den Check_Diagonal_Loop de tiep tuc kiem tra duong cheo tiep theo

    add si, dx                          ; Cong si voi dx de di chuyen den o tiep theo trong duong cheo
    mov bl, Game_Array[si]              ; Di chuyen gia tri cua o bang tro choi tai vi tri bx vao bl
    cmp al, ds:[bx]                     ; So sanh gia tri cua o Do voi gia tri ban dau trong al
    jne Check_Diagonal_Loop             ; Neu khong khop, nhay den Check_Diagonal_Loop de tiep tuc kiem tra duong cheo tiep theo
    
    ; Tuong tu 4 Dong Code tren
    add si, dx
    mov bl, Game_Array[si]
    cmp al, ds:[bx]
    jne Check_Diagonal_Loop

    mov Win_Flag, 1                     ; Neu tat ca cac o trong duong cheo deu giong nhau va khong phai la o trong, dat co chien thang thanh 1
    ret                                 ; Ket thuc ham



  
  
  
  
  

; HAM HIEN THI THONG BAO KET THUC TRO CHOI VA KET QUA TRO CHOI
Game_Over:
    call Clear_Screen                   ; Xoa man hinh truoc khi in ket qua
    lea dx, Game_Start_Message          ; Chuan bi thong bao bat dau tro choi
    call Print                          ; Goi ham in ra thong bao bat dau tro choi
     
    lea dx, New_Line
    call Print

    lea dx, Board_Game                  
    call Print                          ; In ra bang tro choi da hoan thanh

    lea dx, New_Line
    call Print

    lea dx, Game_Over_Message           ; Chuan bi thong bao ket thuc tro choi
    call Print                          ; Goi ham in

    cmp Win_Flag, 1                     ; Neu co = 1 se co 1 nguoi chien thang
    je Print_Winner                     ; Nhay den Print_Winner de in ra nguoi chien thang

    cmp Win_Flag, 2                     ; Neu co = 2 tro choi ket thuc trang thai hoa
    je Print_Draw                       ; Nhay den Print_Draw de in ra thong bao hoa

    jmp Fim                             ; Neu khong chuong trinh se nhay den Fim de ket thuc chuong trinh


; HAM IN RA NGUOI CHIEN THANG
Print_Winner:
    lea dx, Player_Message
    call Print

    lea dx, Player
    call Print

    lea dx, Win_Message
    call Print

    jmp Fim


; HAM IN TRANG THAI HOA
Print_Draw:
    lea dx, Draw_Message
    call Print

    jmp Fim


    
; HAM THIET LAP MANG LUU TRU DIA CHI DEN BANG TRO CHOI  
Set_Game_Array:
    
    lea si, Board_Game                  ; Lay dia chi cua Board_Game vao si
    lea bx, Game_Array                  ; Lay dia chi cua Game_Array vao bx
    mov cx, 9                           ; Thiet lap bo dem cx de lap 9 lan (cho 9 o trong bang tro choi)
    
    ; Duyet qua tung o trong bang tro choi
    Loop_1:
    ; So sanh gia tri cua cx voi 6 va 3 
    ; Dieu nay duoc thuc hien de kiem tra xem co phai dang o cuoi cua hang thu 2 hoac hang thu 3 trong bang tro choi
    cmp cx, 6                          
    je Add_1                            ; Neu cx bang 6 hoac 3, nhay den nhan Add_1 de bo qua cac ky tu xuong dong (CR va LF, tuc la 13, 10)
    cmp cx, 3
    je Add_1
    jmp Add_2                           ; Neu cx khong phai la 6 hoac 3, nhay den nhan Add_2
  
  
Add_1:
    add si, 1                           ; Bo qua ky tu xuong dong
   
   
Add_2:
    mov ds:[bx], si                     ; Luu dia chi cua o hien tai vao Game_Array
    add si, 2                           ; Tang gia tri cua si len 2 de di chuyen den o tiep theo trong Board_Game, bo qua ky tu doc (|)
    inc bx                              ; Tang gia tri cua BX len 1 de tro den vi tri tiep theo trong Game_Array
    Loop Loop_1                         ; Giam cx va lap lai vong lap neu cx chua bang 0
    ret
 

; Ham in chuoi tu vi tri dang tro toi tren man hinh
Print:
    mov ah, 9                            
    int 21h                             
    ret                                 
    
; Ham xoa man hinh de chuan bi cho viec in noi dung moi
Clear_Screen:
    ; Su dung cac ham BIOS de xoa man hinh
    ; trong do int 10h la ham goi de dieu khien hien thi tren man hinh VGA
    mov ah, 0fh
    int 10h
    mov ah, 0
    int 10h
    ret 
 
; Ham doc 1 ki tu tu ban phim
Read_keyboard:
    mov ah, 1
    int 21h
    ret
    
Fim: 
    ; Danh dau ket thuc chuong trinh
    jmp Fim 

Code Ends

End Start

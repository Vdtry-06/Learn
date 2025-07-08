; nhap ki tu
; xuong dong
; chuyen thuong thanh hoa
; in ra ki tu
.Model Small
.Stack 100H
.Data
    CRLF DB 13, 10, '$'; ky tu xuong dong
    HAM1 DB ?, '$'
.Code
MAIN PROC; thu tuc chinh
    ;khoi tao DS
    MOV AX, @Data; khoi dau thanh ghi DS
    MOV DS, AX; tro thanh ghi DS ve dau doan DATA
    
    ; nhap vao 1 ki tu thuong
    MOV AH, 1;
    INT 21H
    
    SUB AL, 20H; doi thuong thanh hoa 
    MOV HAM1, AL; luu gtri vua nhap vao AL
      
    ;in ra dau xuong dong  
    LEA DX, CRLF
    MOV AH, 9
    INT 21H
      
    ;in ra chuoi ki tu vua nhap
    LEA DX, HAM1;
    MOV AH, 9
    INT 21H
    
    
    MOV AH, 4CH
    INT 21H
MAIN Endp
END
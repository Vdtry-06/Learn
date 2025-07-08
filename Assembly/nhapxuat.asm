.Model Small
.Stack 100H
.Data
    CRLF DB 13, 10, '$'; ky tu xuong dong
    HAM1 DB ?
.Code
MAIN PROC; thu tuc chinh
    ;khoi tao DS
    MOV AX, @Data; khoi dau thanh ghi DS
    MOV DS, AX; tro thanh ghi DS ve dau doan DATA
    
    MOV AH, 1; su dung ham ngat 1 cua ngat INT 21H
    INT 21H
    MOV HAM1, AL; gan gia tri vua nhap duoc luu o AL vao bien HAM1     
    
    LEA DX, CRLF; goi ham xuong dong
    MOV AH, 9
    INT 21H
    
    MOV AH, 2; in ra ki tu vua nhap
    MOV DL, HAM1
    INT 21H
    
    MOV AH, 4CH; ket thuc chuong trinh
    INT 21H
MAIN Endp
END
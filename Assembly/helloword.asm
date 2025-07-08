.Model Small
.Stack 100H
.Data
    CRLF DB 13, 10, '$'; ky tu xuong dong
    HAM1 DB 'Hello world !$'
.Code
MAIN PROC; thu tuc chinh
    ;khoi tao DS
    MOV AX, @Data; khoi dau thanh ghi DS
    MOV DS, AX; tro thanh ghi DS ve dau doan DATA
    
    MOV AH, 9; lenh goi ham 09h cua ngat 21 in 1 xau ki tu
    LEA DX, HAM1;
    INT 21H
    
    MOV AH, 4CH
    INT 21H
MAIN Endp
END
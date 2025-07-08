;nhap chuoi
;in thong bao
;in chuoi
.Model Small
.Stack 100H
.Data
    CRLF DB 13, 10, 'Xau vua nhap la: $'; 10 xuong dong 13 lui dau dong
    str DB 100 dup('$'); chuoi 100ptu
.Code
    MAIN PROC; thu tuc chinh
        ;khoi tao DS
        MOV AX, @Data; khoi dau thanh ghi DS
        MOV DS, AX; tro thanh ghi DS ve dau doan DATA
        
        ; nhap xau vao ban phim
        MOV AH, 10; 10 = 0AH
        LEA DX, str; tro den dia chi dau HAM1
        INT 21H 
             
        ;in xau xuong dong
        MOV AH, 9 
        LEA DX, CRLF
        INT 21H
        
        ;dua DX chi ve ptu thu 2 cua mang
        ;la ki tu dau tien duoc nhap vao
        LEA DX, str + 2; 256, 5, xau vua nhap
        INT 21H; in ra
        
        MOV AH, 4CH
        INT 21H
    MAIN Endp
END
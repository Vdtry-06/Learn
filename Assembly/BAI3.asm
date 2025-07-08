.MODEL SMALL
.STACK 100
.DATA  
    TB2 DB 10, 13, 'Chuoi da nhap la: $' ;10 xuong dong , 13 lui dau dong*
    TB1 DB 10, 13, 'Nhap chuoi tu ban phim: $' 
    STR DB 100 dup('$') ;
.CODE
    MAIN PROC 
        
        MOV AX, @DATA
        MOV DS, AX        ;khoi tao thanh ghi ds 
        
        MOV AH, 9         ;in chuoi TB1 
        LEA DX, TB1
        INT 21H
          
        ;nhap chuoi ky tu
        MOV AH, 10        ;10=0ah
        LEA DX, STR       ;tro den dia chi dau str
        INT 21H 
        
        MOV AH, 9         ; in chuoi TB2  
        LEA DX, TB2
        INT 21H           ;in ra
            
        ;dua dx chi ve phan tu thu 2 cua mang la  
        ; ky tu dau tien duoc nhap vao
        LEA DX, STR + 2   ;256,5,h,e,l,l,o      
        INT 21H           ;in ra xau nhap tu ban phim
        
        MOV AH, 4CH
        INT 21H
            
    MAIN Endp
END
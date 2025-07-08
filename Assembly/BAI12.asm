.MODEL SMALL
.STACK 100
.DATA
    muoi DW 10
    TB2 DB 10, 13, 'Ket qua la: $'
    TB1 DB 10, 13, 'Nhap 1 so tu ban phim: $' 
.CODE
    MAIN PROC
        
        MOV AX,@DATA
        MOV DS, AX       ;khoi tao thanh ghi ds
        
        MOV AH, 9        ; in chuoi tb1
        LEA DX, TB1
        INT 21H
        
        MOV AH, 1        ;nhap 1 ky tu tu ban phim
        INT 21H
          
        SUB AL, '0'      ;vd :chuyen ky tu'5' ve so 5 
        MOV CX, 0        ;cx=0 xac dinh gia tri so da nhap tu ban phim
        MOV CL, AL       ;cl=5
        
        LEA DX, TB2      ;in chuoi tb2
        MOV AH, 9
        INT 21H
                         ;1*2*3*4*5       
        MOV AX, 1        ;khoi tao ket qua ban dau =1
        MOV BX, 1        ;bien tang 
        
        GIAITHUA:        ;tinh giai thua tra ve 1 so
            
            MUL BX       ;ax * bx luu vao trong ax
            INC BX       ;increase:tang gia tri bx len 1
            CMP BX, CX   ;so sanh bx voi cx 
            JLE GIAITHUA ;neu bx<=cx thi tiep tuc lap
        MOV CX, 0
             
        LAPPUSH:         ;lay tu ky tu cua so 120 vao day vao trong ngan xep
            
            MOV DX, 0
            DIV muoi     ;chia cho 10
            ADD DX, '0' 
            PUSH DX      ;day vao ngan xep
            INC CX       ;increase : tang cx 1 don vi
            CMP AX, 0
            JNE LAPPUSH
        
        HIENTHI:         ;hien thi tung ky tu o trong ngan xep
            
            POP DX       ;lay 1 so o dau ngan xep
            MOV AH, 2    ;hien ki tu len man hinh
            INT 21H
            LOOP HIENTHI              
        
        MOV AH, 4CH
        INT 21H
         
    MAIN Endp
END MAIN
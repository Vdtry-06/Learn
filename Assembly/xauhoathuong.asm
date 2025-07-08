.Model Small
.Stack 100H
.Data
    TB1 DB 10, 13, 'Chuyen sang chuoi in thuong: $'
    TB2 DB 10, 13, 'Chuyen sang chuoi in hoa: $'
    STR DB 256 dup("$"); khoi tao chuoi str
.Code
MAIN PROC; thu tuc chinh
    ;khoi tao DS
    MOV AX, @Data; khoi dau thanh ghi DS
    MOV DS, AX; tro thanh ghi DS ve dau doan DATA
    
    ;nhap chuoi  
    LEA DX, STR; tro den dia chi STR
    MOV AH, 10; nhap xau
    INT 21H 
    
    ;in tb1 
    MOV AH, 9; hien xau tb1
    LEA DX, TB1
    INT 21H
    CALL LOWER; goi ham in thuong
    
    ;in tb2
    MOV AH, 9
    LEA DX, TB2; tro den dia chi STR
    INT 21H
    CALL UPPER; goi ham in hoa
    
    MOV AH, 4CH
    INT 21H
MAIN Endp
LOWER PROC
    LEA SI, STR + 2
    LAP1:  ; 1 xau: ktra tung ki tu 1
        MOV DL, [SI]; DL = M[SI]
        CMP DL, 'A'
        JL IN1; jump less  
        CMP DL, 'Z'
        JG IN1; jump greater
        ADD DL, 32; hoa thanh thuong
    IN1:
        MOV AH, 2; in ky tu
        INT 21H
        INC SI; increase
        CMP [SI], '$'; so sanh co phai ki tu cuoi cung ko 
        JNE LAP1 ; jump not equal
    RET; return
LOWER endp

UPPER PROC 
    LEA SI, STR + 2
    LAP2:
        MOV DL, [SI]
        CMP DL, 'a'
        JL IN2
        CMP DL, 'z'
        JG IN2
        SUB DL, 32
    IN2:
        MOV AH, 2;
        INT 21H
        INC SI
        CMP [SI], '$'
        JNE LAP2
    RET
UPPER endp 
END MAIN
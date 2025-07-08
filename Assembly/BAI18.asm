.MODEL SMALL
.STACK 100H

.DATA
    STR DB 255 dup('$')
    CNT DB 0                  ; bien dem de dem so luong xau 'ktmt'
    TB1 DB 10, 13, "Nhap xau tu ban phim: $"
    RES DB 10, 13, "So lan xuat hien cua chuoi 'ktmt' la : $"

.CODE
    MAIN PROC
        MOV AX, @data
        MOV DS, AX

        MOV AH, 9             ; in thong bao yeu cau nhap chuoi
        LEA DX, TB1
        INT 21H

        MOV AH, 10            ; nhap chuoi tu ban phim
        LEA DX, STR
        INT 21H

        MOV AH, 9             ; in thong bao ket qua
        LEA DX, RES
        INT 21H

        MOV CX, 0             ; khoi tao dem cx ban dau = 0
        MOV BX, 3             ; vi tri index cua xau can kiem tra bat dau tu 3
    
    CHECK_LOOP:
        
        MOV AL, STR[BX]       ; lay ki tu tai vi tri bx trong chuoi STR
        CMP AL, '$'           ; kiem tra ki tu ket thuc cua chuoi
        JE END_CHECK_LOOP     ; neu gap ki tu '$' thoat khoi vong lap kiem tra

        CMP AL, 't'           ; so sanh ki tu hien tai voi 't'
        JNE NOT_MATCHED       ; neu khong, bo qua kiem tra ki tu tiep theo

        MOV AL, STR[BX - 1]   ; lay ki tu truoc ki tu 't'
        CMP AL, 'm'           ; so sanh voi 'm'
        JNE NOT_MATCHED       ; neu khong khop, bo qua kiem tra ki tu tiep theo

        MOV AL, STR[BX - 2]   ; lay ki tu truoc ki tu 'm'
        CMP AL, 't'           ; so sanh voi 't'
        JNE NOT_MATCHED       ; neu khong khop, bo qua kiem tra ki tu tiep theo

        MOV AL, STR[BX - 3]   ; lay ki tu truoc ki tu 't'
        CMP AL, 'k'           ; so sanh voi 'k'
        JNE NOT_MATCHED       ; neu khong khop, bo qua kiem tra ki tu tiep theo

        INC CX                ; neu chuoi con khop tang bien dem
    
    NOT_MATCHED:
        
        INC BX                ; tang bien bx
        JMP CHECK_LOOP        ; lap lai qua trinh kiem tra

    END_CHECK_LOOP:
        

        MOV DL, CL            ; Dat ket qua (so lan xuat hien cua chuoi con) vao DL de in ra man hinh
        ADD DL, '0'           ; Chuyen ket qua thanh ki tu
        MOV AH, 2      
        INT 21H               ; in ket qua ra man hinh

        MOV AH, 4CH           ; ket thuc chuong trinh
        INT 21H               ; Goi ham ngat de ket thuc

    MAIN Endp
END MAIN

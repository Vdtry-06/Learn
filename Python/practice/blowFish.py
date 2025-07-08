# Blowfish P-array và S-box giả lập (rút gọn để minh hoạ)
P = [0x243F6A88, 0x85A308D3] + [0] * 16  # P-array giả lập, đủ 18 phần tử
S = [[i ^ 0xA5 for i in range(256)] for _ in range(4)]  # S-box giả lập

# Hàm F trong Blowfish
def F(x):
    a = (x >> 24) & 0xFF
    b = (x >> 16) & 0xFF
    c = (x >> 8) & 0xFF
    d = x & 0xFF
    return ((S[0][a] + S[1][b]) ^ S[2][c]) + S[3][d]

# Hàm mã hóa 1 block
def encrypt_block(left, right):
    for i in range(16):  # 16 vòng lặp mã hóa
        left ^= P[i]
        right ^= F(left)
        left, right = right, left  # Hoán đổi left và right
    left, right = right, left  # Hoán đổi cuối cùng
    right ^= P[16]  # Áp dụng P[16] vào right
    left ^= P[17]   # Áp dụng P[17] vào left
    return left, right

# Hàm giải mã 1 block
def decrypt_block(left, right):
    for i in reversed(range(2, 18)):  # Đảo ngược thứ tự vòng mã hóa
        left ^= P[i]
        right ^= F(left)
        left, right = right, left  # Hoán đổi left và right
    left, right = right, left  # Hoán đổi cuối cùng
    right ^= P[1]  # Áp dụng P[1] vào right
    left ^= P[0]   # Áp dụng P[0] vào left
    return left, right

# Hàm chuyển đổi từ bytes thành các từ (words)
def bytes_to_words(b):
    return int.from_bytes(b[:4], 'big'), int.from_bytes(b[4:], 'big')

# Hàm chuyển đổi từ words về lại bytes
def words_to_bytes(l, r):
    return l.to_bytes(4, 'big') + r.to_bytes(4, 'big')

# Test: Mã hóa và giải mã
key = b'examplekey123456'  # khóa 16 byte
plaintext = b'ABCDEFGH'     # 8 byte = 64 bit block

# Mã hóa
l, r = bytes_to_words(plaintext)
l_enc, r_enc = encrypt_block(l, r)
ciphertext = words_to_bytes(l_enc, r_enc)
print("Encrypted:", ciphertext.hex())

# Giải mã
l_dec, r_dec = bytes_to_words(ciphertext)
l_dec, r_dec = decrypt_block(l_dec, r_dec)
decrypted_text = words_to_bytes(l_dec, r_dec)
print("Decrypted:", decrypted_text.decode())

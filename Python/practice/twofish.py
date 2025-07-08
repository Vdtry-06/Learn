def xor_bytes(a, b):
    return bytes(x ^ y for x, y in zip(a, b))

def simple_f_function(data, key):
    # S-box đơn giản (not secure)
    return bytes([(b * 7 + key[i % len(key)]) % 256 for i, b in enumerate(data)])

def encrypt_block(plaintext, key):
    # Chia block 16 byte làm 2 nửa
    L, R = plaintext[:8], plaintext[8:]
    F = simple_f_function(R, key)
    L_new = xor_bytes(L, F)
    return R + L_new  # swap 2 nửa (Feistel)

def decrypt_block(ciphertext, key):
    R, L_new = ciphertext[:8], ciphertext[8:]
    F = simple_f_function(R, key)
    L = xor_bytes(L_new, F)
    return L + R

# === THỬ ===
key = b"12345678abcdefgh"  # 16 byte key
plaintext = b"HelloWorld123456"  # đúng 16 byte

cipher = encrypt_block(plaintext, key)
print("Encrypted:", cipher.hex())

plain_back = decrypt_block(cipher, key)
print("Decrypted:", plain_back.decode())

import random


# Hàm kiểm tra số nguyên tố đơn giản
def is_prime(n):
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


# Hàm sinh số nguyên tố ngẫu nhiên
def generate_prime(bits):
    while True:
        p = random.getrandbits(bits)
        if is_prime(p):
            return p


# Hàm sinh khóa công khai và khóa bí mật
def generate_keys(bits=512):
    p = generate_prime(bits // 2)  # Sinh số nguyên tố p
    q = generate_prime(bits // 2)  # Sinh số nguyên tố q
    n = p * q  # Tính n
    return (n), (p, q)


# Hàm tính căn bậc hai modulo p (Sử dụng phương pháp Tonelli-Shanks)
def mod_sqrt(c, p):
    """Tìm căn bậc hai của c modulo p, với p là số nguyên tố"""
    # Nếu p mod 4 == 3, ta có thể tính căn bậc hai trực tiếp
    if p % 4 == 3:
        return pow(c, (p + 1) // 4, p)

    # Nếu không, sử dụng phương pháp Tonelli-Shanks
    s = 0
    t = p - 1
    while t % 2 == 0:
        s += 1
        t //= 2

    # Chọn một số ngẫu nhiên không phải căn bậc hai mod p
    n = 2
    while pow(n, (p - 1) // 2, p) == 1:
        n += 1

    x = pow(c, (t + 1) // 2, p)
    z = pow(n, t, p)
    m = s
    c = c
    r = x

    while True:
        y = c
        for i in range(1, m):
            if pow(y, 2, p) == 1:
                break
            y = pow(y, 2, p)

        if i == m:
            return r

        b = pow(z, 2 ** (m - i - 1), p)
        m = i
        c = b
        r = (r * b) % p


# Hàm mã hóa
def encrypt(m, n):
    # Mã hóa tin nhắn m: c = m^2 % n
    c = (m * m) % n
    return c


# Hàm giải mã
def decrypt(c, p, q):
    # Tính căn bậc hai modulo p và q
    sqrt_p = mod_sqrt(c, p)
    sqrt_q = mod_sqrt(c, q)

    # Áp dụng phương pháp Chinese Remainder Theorem (CRT)
    # Tính toán các nghiệm từ căn bậc hai modulo p và q
    p_inv = mod_inverse(p, q)
    q_inv = mod_inverse(q, p)

    # Tìm nghiệm của phương trình x^2 ≡ c (mod n)
    x1 = (sqrt_p + p * (sqrt_q - sqrt_p) * p_inv) % (p * q)
    x2 = (sqrt_p - p * (sqrt_q - sqrt_p) * p_inv) % (p * q)
    x3 = (sqrt_p + p * (sqrt_q + sqrt_p) * p_inv) % (p * q)
    x4 = (sqrt_p - p * (sqrt_q + sqrt_p) * p_inv) % (p * q)

    return (x1, x2, x3, x4)


# Hàm tính nghịch đảo modulo (Dùng thuật toán Extended Euclidean)
def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    if m == 1:
        return 0
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += m0
    return x1


# Test thuật toán Rabin
if __name__ == "__main__":
    # Sinh khóa
    n, (p, q) = generate_keys()
    print(f"Public Key (n): {n}")
    print(f"Private Key (p, q): ({p}, {q})")

    # Mã hóa
    message = 12345  # Tin nhắn muốn mã hóa
    ciphertext = encrypt(message, n)
    print(f"Encrypted message: {ciphertext}")

    # Giải mã
    decrypted_messages = decrypt(ciphertext, p, q)
    print(f"Decrypted possible messages: {decrypted_messages}")

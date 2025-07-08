def Exp(p, e):
    P = 1
    for i in range(e):
        P *= p
    return P

def Exp(p, e):
    if e == 0: return 1
    if e&1: return Exp(p, e - 1) * p
    P = Exp(p, e // 2) ####
    return P * P

def Pow(p, e):
    P = Exp(p, e)
    res = 0
    a = [0] * P
    for i in range(P):
        a[i * i % P] += 1
    for i in range(P):
        res += a[i] * a[(i + 1) % P]
    sq = 0
    for i in range(0, P, p):
        sq = i * i % P
        res += a[(sq + 1) % P]
    res *= P // p * (p - 1)
    if e > 1:
        res += Pow(p, e - 2) * p * p * p
    else:
        res += 1
    return res

def Zeroa(n):
    res = 1 + 3 * a[0]
    for i in range(n):
        res += a[i] * (2 * a[i] + a[(n - i) % n]) ###
    return res

def Diag(n):
    res = 0
    for i in range(1, n):
        res += a[2 * i * i % n]
    return res

n = int(input())
a = [0] * n
N, res, p = n, 1, 2
while p * p <= n:
    if n % p == 0:
        e = 0
        while n % p == 0:
            e += 1
            n //= p
        res *= Pow(p, e)
    p += 1
if n != 1:
    res *= Pow(n, 1)
a = [0] * N
for i in range(1, N):
    a[i * i % N] += 1
res -= Zeroa(N)
res += Diag(N)
print(res // 2)
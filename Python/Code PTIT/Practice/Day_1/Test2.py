def Sang(n):
    f = [True] * (n + 1)
    p = 2
    while p * p <= n:
        if f[p]:
            for i in range(p * p, n + 1, p):
                f[i] = False
        p += 1
    return [p for p in range(2, n + 1) if f[p]]

def count(n):
    MAX = int(n**0.5) + 1
    prime = Sang(MAX)
    cnt = 0
    for p in prime:
        if p**8 <= n:
            cnt += 1

    for i in range(len(prime)):
        for j in range(i + 1, len(prime)):
            p1 = prime[i]
            p2 = prime[j]
            if p1**2 * p2**2 <= n:
                cnt += 1
            else:
                break
    return cnt

n = int(input())
res = count(n)
print(res)
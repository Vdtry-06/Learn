MOD = 10**9 + 7

def modInv(x, p):
    return pow(x, p - 2, p)

def comb(n, k, f, rev_f):
    if k > n or k < 0:
        return 0
    return f[n] * rev_f[k] % MOD * rev_f[n - k] % MOD

def solve(n, k, a):
    a.sort()
    f = [1] * (n + 1)
    rev_f = [1] * (n + 1)
    for i in range(2, n + 1):
        f[i] = f[i - 1] * i % MOD

    rev_f[n] = modInv(f[n], MOD)
    for i in range(n - 1, 0, -1):
        rev_f[i] = rev_f[i + 1] * (i + 1) % MOD

    s = 0
    for i in range(n):
        if i >= k - 1:
            mx = comb(i, k - 1, f, rev_f)
            s = (s + a[i] * mx) % MOD
        if n - i - 1 >= k - 1:
            mi = comb(n - i - 1, k - 1, f, rev_f)
            s = (s - a[i] * mi) % MOD
    s = (s + MOD) % MOD
    return s

n, k = map(int, input().split())
a = list(map(int, input().split()))
res = solve(n, k, a)
print(res)

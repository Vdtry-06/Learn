def check(x, b):
    if x == b: return 0
    for i in range(len(x)):
        b = b[1:] + b[0]
        if x == b: return i + 1
    return -1

n = int(input())
a = []
ok = True
res = 10**5
for _ in range(n):
    a.append(input())
for i in range(n):
    cnt = 0
    for j in range(n):
        if i != j:
            num = check(a[i], a[j])
            if num == -1:
                ok = False
                break
            else: cnt += num
    res = min(res, cnt)

print(res if ok else -1)

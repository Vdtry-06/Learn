a = []
n = int(input())
for i in range(n):
    x = list(str(i) for i in input().split())
    a.append(len(x))

flag = []
cnt = 0
for i in range(len(a)):
    if a[i] == 6 or a[i] == 8:
        flag.append(1)
    else:
        flag.append(2)

flag.append(0)
res = []
cnt = 1
for i in range(1, len(flag)):
    if flag[i] == flag[i - 1]:
        cnt += 1
    else:
        tmp = cnt
        if flag[i - 1] == 2:
            tmp = int(tmp / 4)
            for j in range(0, tmp):
                res.append(flag[i - 1])
        else:
            res.append(flag[i - 1])
        cnt = 1

print(len(res))
for x in res:
    print(x)


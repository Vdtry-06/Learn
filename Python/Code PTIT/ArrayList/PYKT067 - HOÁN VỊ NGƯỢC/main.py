d = 0
res = []
f = [0] * 10
visited = [False] * 10

def Try(i, n):
    global res, d
    for j in range(1, n + 1):
        if not visited[j]:
            f[i] = n - j + 1
            visited[j] = True
            if i == n:
                d += 1
                tmp = ""
                for idx in range(1, i + 1):
                    tmp += str(f[idx])
                res.append(tmp)
            else:
                Try(i + 1, n)
            visited[j] = False

for t in range(int(input())):
    n = int(input())
    Try(1, n)
    print(d)
    print(" ".join(res))
    res = []
    d = 0

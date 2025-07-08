for t in range(int(input())):
    n, m = list(int(i) for i in input().split())
    a, b = [], []

    for _ in range(n):
        x = list(int(i) for i in input().split())
        a.append(x)

    for _ in range(3):
        x = list(int(i) for i in input().split())
        b.append(x)

    s = 0
    for i in range(n):
        if i == n - 2: break
        for j in range(m):
            if j == m - 2: break
            for k in range(3):
                for h in range(3):
                    s += b[k][h] * a[i + k][j + h]

    print(s)

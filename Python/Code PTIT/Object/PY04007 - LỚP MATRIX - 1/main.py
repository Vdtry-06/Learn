t = int(input())

for _ in range(t):
    n, m = list(int(i) for i in input().split())
    a, b = [[0] * m] * n, []

    for i in range(n):
        a[i] = list(int(x) for x in input().split())
    for j in range(m):
        tmp = []
        for i in range(n):
            tmp.append(a[i][j])
        b.append(tmp)
    # for i in range(len(b)):
    #     print(b[i])

    for i in range(n):
        for j in range(n):
            s = 0
            for k in range(m):
                s += a[i][k] * b[k][j]
            print(s, end = ' ')
        print()
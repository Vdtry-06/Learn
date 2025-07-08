import re

for t in range(int(input())):
    n, m = list(int(i) for i in input().split())
    a, b = [[0] * m] * n, []

    for i in range(n):
        a[i] = list(int(i) for i in re.split(r'\s+', input().strip()))

    for j in range(m):
        tmp = []
        for i in range(n):
           tmp.append(a[i][j])
        b.append(tmp)

    for i in range(n):
        for j in range(n):
            s = 0
            for k in range(m):
                s += a[i][k] * b[k][j]
            print(s, end = ' ')
        print()
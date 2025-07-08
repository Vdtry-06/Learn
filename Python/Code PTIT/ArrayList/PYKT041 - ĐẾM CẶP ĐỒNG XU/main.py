a = []
n = int(input())
for _ in range(n):
    x = list(str(i) for i in input())
    a.append(x)

res = 0
for i in range(n):
    for j in range(n):
        # print(a[i][j], end = ' ')
        if a[i][j] == 'C':
            for k in range(i + 1, n):
                if a[k][j] == 'C': res += 1
            for k in range(j + 1, n):
                if a[i][k] == 'C': res += 1
    # print()
print(res)

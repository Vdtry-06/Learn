n = int(input())
a = []
for i in range(n):
    b = list(int(i) for i in input().split())
    a.append(b)
k = int(input())
s = 0
for i in range(n):
    for j in range(i, n):
        s += a[i][j]
        # print(a[i][j], end = ' ')
    print()
    for j in range(0, i + 1):
        s -= a[i][j]
s = abs(s)
print("YES" if s <= k else "NO", s, sep = "\n")
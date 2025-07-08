from math import gcd
a = []
n = int(input())
a = list(int(i) for i in input().split())
a.sort()
for i in range(n):
    for j in range(i + 1, n):
        if gcd(a[i], a[j]) == 1:
            print(a[i], a[j], sep = ' ')


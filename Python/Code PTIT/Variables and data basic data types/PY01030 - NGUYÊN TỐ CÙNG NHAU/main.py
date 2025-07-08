import math

n, k = map(int, input().split())
st = int(math.pow(10, k - 1))
en = int(math.pow(10, k))

d = 0
for i in range(st, en, 1):
    if math.gcd(n, i) == 1: 
        print(i, end = ' ')
        d += 1
        if d == 10:
            print()
            d = 0
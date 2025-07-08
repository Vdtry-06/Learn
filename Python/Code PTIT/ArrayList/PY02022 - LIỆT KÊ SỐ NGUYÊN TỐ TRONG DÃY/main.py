import math

def prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

n = int(input())
a = list(int(i) for i in input().split())
mp = {}
for x in a:
    if prime(x):
        if x in mp:
            mp[x] += 1
        else:
            mp[x] = 1
for x in mp:
    print(x, mp.get(x), sep = ' ')

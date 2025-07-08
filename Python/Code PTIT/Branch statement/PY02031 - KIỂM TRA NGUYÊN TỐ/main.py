import math

def Prime(n):
    if n < 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True

n, m = map(int, input().split())
a = []
for i in range(n):
    row = list(map(int, input().split()))
    a.append(row)

for row in range(n):
    for colm in range(m):
        if Prime(a[row][colm]):
            print(1, end = ' ')
        else:
            print(0, end = ' ')
    print()
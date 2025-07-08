n = int(input())
a = []
while True :
    x = [int(x) for x in input().split()]
    a.extend(x)
    if len(a) == n : break

b, c = [], []
for i in range(n):
    if a[i] % 2 == 0: b.append(a[i])
    else: c.append(a[i])

b.sort(reverse = True)
c.sort()
for i in range(n):
    if a[i] % 2 == 0:
        print(b[-1], end = ' ')
        b.pop()
    else:
        print(c[-1], end = ' ')
        c.pop()


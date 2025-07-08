for t in range(int(input())):
    n = int(input())
    d = 0
    while n % 7 != 0:
        s = str(n)
        n += int(s[::-1])
        d += 1
    if d > 1000:
        print(-1)
    else:
        print(n)

a, k, n = map(int, input().split())

Check = False

for i in range(k - a, n - a + 1, k):
    if (i + a) % k == 0 and i > 0:
        Check = True
        print(i, end = ' ')

if Check == False:
    print(-1)
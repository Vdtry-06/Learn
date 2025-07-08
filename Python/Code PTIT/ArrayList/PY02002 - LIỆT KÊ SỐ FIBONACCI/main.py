f = [1] * 93

def fibo(n):
    if n == 1 or n == 2:
        return 1
    f[1], f[2] = 1, 1
    for i in range(3, 93):
        f[i] = f[i - 1] + f[i - 2]
    return f[n];


for t in range(int(input())):
    a, b = map(int, input().split())
    
    for i in range(a, b + 1):
        print(fibo(i), end = ' ')
    print()
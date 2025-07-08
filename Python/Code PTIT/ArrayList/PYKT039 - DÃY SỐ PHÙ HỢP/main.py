def check(a, b, n):
    for i in range(n):
        if a[i] > b[i]:
            return False
    return True

for t in range(int(input())):
    n = int(input())
    a = sorted(list(int(i) for i in input().split()))
    b = sorted(list(int(i) for i in input().split()))
    if check(a, b, n) :
        print("YES")
    else:
        print("NO")

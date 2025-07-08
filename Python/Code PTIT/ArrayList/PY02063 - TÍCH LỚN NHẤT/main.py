n = int(input())
a = list(map(int, input().split()))
a = sorted(a)
len_a = len(a)
mx = max({
    a[0] * a[1],
    a[0] * a[1] * a[2],
    a[0] * a[1] * a[len_a - 1],
    a[len_a - 1] * a[len_a - 2],
    a[len_a - 1] * a[len_a - 2] * a[len_a - 3]
    })
print(mx)

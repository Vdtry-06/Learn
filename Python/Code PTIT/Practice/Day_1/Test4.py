def merge_cnt(a, tmp, l, r):
    if l == r:
        return 0
    m = (l + r) // 2
    cnt = 0
    cnt += merge_cnt(a, tmp, l, m)
    cnt += merge_cnt(a, tmp, m + 1, r)
    cnt += merge(a, tmp, l, m, r)
    return cnt

def merge(a, tmp, l, m, r):
    i, j, k, cnt = l, m + 1, l, 0
    while i <= m and j <= r:
        if a[i] <= a[j]:
            tmp[k] = a[i]
            i += 1
        else:
            tmp[k] = a[j]
            cnt += (m - i + 1)
            j += 1
        k += 1

    while i <= m:
        tmp[k] = a[i]
        i += 1
        k += 1

    while j <= r:
        tmp[k] = a[j]
        j += 1
        k += 1

    for i in range(l, r + 1):
        a[i] = tmp[i]

    return cnt

def count_(a, n):
    tmp = [0] * n
    return merge_cnt(a, tmp, 0, n - 1)

n = int(input())
a = list(map(int, input().split()))
res = count_(a, n)
print(res)
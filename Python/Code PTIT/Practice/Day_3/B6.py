def binary(n, q, queries):
    f = [0] * (n + 2)

    for x, y in queries:
        f[x] += 1
        f[y + 1] -= 1

    res = []
    cur = 0
    for i in range(1, n + 1):
        cur += f[i]
        res.append(cur % 2)

    return res


n, q = map(int, input().split())
q = [tuple(map(int, input().split())) for _ in range(q)]

res = binary(n, q, q)

print(' '.join(map(str, res)))

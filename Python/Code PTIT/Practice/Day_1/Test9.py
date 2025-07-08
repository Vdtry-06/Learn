def count_sum_k(matrix, n, m, k):
    cnt = 0
    for r1 in range(n):
        col_sum = [0] * m
        for r2 in range(r1, n):
            for c in range(m):
                col_sum[c] += int(matrix[r2][c])

            cur_sum = 0
            sum_cnt = {0: 1}
            for val in col_sum:
                cur_sum += val
                if cur_sum - k in sum_cnt:
                    cnt += sum_cnt[cur_sum - k]
                if cur_sum in sum_cnt:
                    sum_cnt[cur_sum] += 1
                else:
                    sum_cnt[cur_sum] = 1
    return cnt

for t in range(int(input())):
    n, m, k = map(int, input().split())
    matrix = [input().strip() for _ in range(n)]

    res = count_sum_k(matrix, n, m, k)
    print(res)
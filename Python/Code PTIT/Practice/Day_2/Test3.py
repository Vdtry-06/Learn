def find(matrix, n, m):
    mx = -1
    mi = 10001
    for r in matrix:
        mx = max(mx, max(r))
        mi = min(mi, min(r))
    lucky_number = mx - mi
    pos = []
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == lucky_number:
                pos.append((i,j))

    if pos:
        print(lucky_number)
        for x in pos:
            print(f"Vi tri [{x[0]}][{x[1]}]")
    else:
        print("NOT FOUND")

n, m = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

find(matrix, n, m)
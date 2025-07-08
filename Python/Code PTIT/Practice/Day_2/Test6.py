def solve(n, m, matrix):
    row_mapped = [[0] * m for _ in range(n)]
    for i in range(n):
        value_to_index = {}
        next_value = 1
        for j in range(m):
            if matrix[i][j] not in value_to_index:
                value_to_index[matrix[i][j]] = next_value
                next_value += 1
            row_mapped[i][j] = value_to_index[matrix[i][j]]
    col_mapped = [[0] * m for _ in range(n)]
    for j in range(m):
        value_to_index = {}
        next_value = 1
        for i in range(n):
            if row_mapped[i][j] not in value_to_index:
                value_to_index[row_mapped[i][j]] = next_value
                next_value += 1
            col_mapped[i][j] = value_to_index[row_mapped[i][j]]
    unique_values = set()
    for i in range(n):
        for j in range(m):
            unique_values.add(col_mapped[i][j])
    print(len(unique_values))

n, m = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]
solve(n, m, matrix)

n, m = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]
solve(n, m, matrix)
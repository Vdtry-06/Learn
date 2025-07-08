class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.rank = [0] * (n + 1)
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if(x != y):
            if self.rank[x] > self.rank[y]:
                self.parent[y] = x
            elif self.rank[x] < self.rank[y]:
                self.parent[x] = y
            else:
                self.parent[y] = x
                self.rank[x] += 1
def solve(q):
    mx = 0
    for x, y, _ in q:
        mx = max(mx, x, y)

    dsu = DSU(mx)
    res = []
    for x, y, z in q:
        if z == 1:
            dsu.union(x, y)
        elif z == 2:
            if dsu.find(x) == dsu.find(y):
                res.append(1)
            else:
                res.append(0)
    for x in res:
        print(x)

q = int(input())
a = [tuple(map(int, input().split())) for _ in range(q)]
solve(a)
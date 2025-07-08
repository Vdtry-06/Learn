import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, other):
        return math.sqrt((self.x - other.x) ** 2 + (self.y - other.y) ** 2)

class Triangle:
    def __init__(self, p1, p2, p3):
        self.p1 = p1
        self.p2 = p2
        self.p3 = p3

    def __str__(self):
        a = self.p1.distance(self.p2)
        b = self.p2.distance(self.p3)
        c = self.p3.distance(self.p1)
        if max(a, b, c) * 2 >= a + b + c:
            return "INVALID"
        return f"{a + b + c:.3f}"

t = int(input())
a = []

for _ in range(t):
    a += list(float(i) for i in input().split())
i = 0
for _ in range(t):
    p1, p2, p3 = Point(a[i], a[i + 1]), Point(a[i + 2], a[i + 3]), Point(a[i + 4], a[i + 5])
    triangle = Triangle(p1, p2, p3)
    i += 6
    print(triangle)
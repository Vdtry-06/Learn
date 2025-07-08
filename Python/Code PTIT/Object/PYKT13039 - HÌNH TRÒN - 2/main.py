import math

a, b = list(float(i) for i in input().split())
c = math.sqrt(a ** 2 + b ** 2)
r = (a + b - c) / 2
x = math.sqrt(pow(b - r, 2) + r * r)
k = (x - r) / (x + r)
res = 2 * math.pi * r **2 / (1 - k ** 2) / a / b
print(f"{res:.4f}")
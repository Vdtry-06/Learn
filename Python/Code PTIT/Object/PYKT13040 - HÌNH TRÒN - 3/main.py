import math

n = float(input())
div = (1 + math.sqrt(2) - math.sqrt(3)) / 4
res = math.sqrt(n) * div
print(f"{res:.4f}")
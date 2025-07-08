import math


class Decimal:
    def __init__(self, up, down):
        self.up = int(up / math.gcd(up, down))
        self.down = int(down / math.gcd(up, down))

    def __str__(self):
        return f"{self.up}/{self.down}"

n, m = list(int(i) for i in input().split())
decimal = Decimal(n, m)
print(decimal)
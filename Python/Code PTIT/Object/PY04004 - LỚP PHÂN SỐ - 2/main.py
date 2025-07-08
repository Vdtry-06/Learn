import math


class Decimal:
    def __init__(self, up1, down1, up2, down2):
        self.up1 = int(up1 / math.gcd(up1, down1))
        self.down1 = int(down1 / math.gcd(up1, down1))
        self.up2 = int(up2 / math.gcd(up2, down2))
        self.down2 = int(down2 / math.gcd(up2, down2))
        up = self.up1 * self.down2 + self.up2 * self.down1
        down = self.down1 * self.down2
        self.up = int(up / math.gcd(up, down))
        self.down = int(down / math.gcd(up, down))

    def __str__(self):
        return f"{self.up}/{self.down}"

n, m, p, q = list(int(i) for i in input().split())
decimal = Decimal(n, m, p, q)
print(decimal)
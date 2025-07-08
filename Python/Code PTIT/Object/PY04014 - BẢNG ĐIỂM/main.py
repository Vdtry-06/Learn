from decimal import Decimal, ROUND_HALF_UP

cnt = 1
class Total:
    def __init__(self, name, a: list):
        global cnt
        self.id = f"HS{cnt:02d}"
        self.name = name
        avg = (sum(a[:2]) * 2 + sum(a[2:])) / 12
        self.avg = avg.quantize(Decimal('0.1'), ROUND_HALF_UP)
        if self.avg >= 9:
            self.type = "XUAT SAC"
        elif self.avg >= 8:
            self.type = "GIOI"
        elif self.avg >= 7:
            self.type = "KHA"
        elif self.avg >= 5:
            self.type = "TB"
        else:
            self.type = "YEU"
        cnt += 1

    def __lt__(self, other):
        if self.avg == other.avg:
            return self.id < other.id
        return self.avg > other.avg

    def __str__(self):
        return f"{self.id} {self.name} {self.avg:.1f} {self.type}"

a = []
for t in range(int(input())):
    name = input()
    scores = list(Decimal(i) for i in input().split())
    a.append(Total(name, scores))
a.sort()
for x in a:
    print(x)


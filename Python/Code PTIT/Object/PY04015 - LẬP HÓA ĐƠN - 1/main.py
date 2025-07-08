cnt = 1
class Bill:
    def __init__(self, name, st, en):
        global cnt
        self.id = f"KH{cnt:02d}"
        self.name = name
        V = en - st
        if V > 100: self.price = ((V - 100) * 200 + 50 * 250) * 1.05
        elif V > 50: self.price = ((V - 50) * 150 + 50 * 100) * 1.03
        else: self.price = V * 100 * 1.02
        cnt += 1

    def __str__(self):
        return f"{self.id} {self.name} {self.price:.0f}"

a = []
for t in range(int(input())):
    a.append(Bill(input(), int(input()), int(input())))
a.sort(key = lambda x : (-x.price, x.id))
for x in a:
    print(x)
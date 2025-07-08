from datetime import datetime

cnt = 1
class TheLoai:
    def __init__(self, name):
        global cnt
        self.id = f"TL{cnt:03d}"
        self.name = name
        cnt += 1
cnt2 = 1
class Phim:
    def __init__(self, id, day, name, amount):
        global cnt2
        self.code = f"P{cnt2:03d}"
        self.id = id
        self.day = day
        date = day
        self.date = datetime.strptime(date, "%d/%m/%Y")
        self.name = name
        self.amount = amount
        cnt2 += 1

    def __str__(self):
        return f"{self.code} {self.id} {self.day} {self.name} {self.amount}"

n, m = list(int(i) for i in input().split())
a = {}
for i in range(n):
    theloai = TheLoai(input())
    a[theloai.id] = theloai.name
b = []
for i in range(m):
    phim = Phim(a[input()], input(), input(), int(input()))
    b.append(phim)

b.sort(key = lambda x: (x.date, x.name, -x.amount))
for x in b:
    print(x)
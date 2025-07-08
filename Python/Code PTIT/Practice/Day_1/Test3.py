cnt = 1
class Cathi:
    def __init__(self, date, hour, id):
        global cnt
        self.date = date
        self.hour = hour
        self.id = id
        self.ma = "C" + str(cnt).zfill(3)
        cnt += 1
    def getDate(self):
        return self.date
    def getHour(self):
        return self.hour
    def getMa(self):
        return self.ma

    def __str__(self):
        return f"{self.ma} {self.date} {self.hour} {self.id}"

with open("CATHI.in", "r") as f:
    n = int(f.readline().strip())
    arr = []

    for _ in range(n):
        date = f.readline().strip()
        hour = f.readline().strip()
        id = f.readline().strip()

        cathi = Cathi(date, hour, id)
        arr.append(cathi)

arr.sort(key = lambda x: (x.getDate(), x.getHour()))

for cathi in arr:
    print(cathi)
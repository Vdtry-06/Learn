mp = {}
def minute(s):
    h, m = s.split(':')
    return int(h) * 60 + int(m)

class Rainfall:
    def __init__(self, name, start, end, quantity):
        self.name = name
        self.time = minute(end) - minute(start)
        self.quantity = quantity

cnt = 1
for t in range(int(input())):
    rainfall = Rainfall(input(), input(), input(), int(input()))
    if mp.get(rainfall.name) == None:
        rainfall.id = f"T{cnt:02d}"
        cnt += 1
        mp[rainfall.name] = rainfall
    else:
        mp[rainfall.name].time += rainfall.time
        mp[rainfall.name].quantity += rainfall.quantity

for i in mp:
    print(mp[i].id, mp[i].name, f"{mp[i].quantity / (mp[i].time / 60):.2f}")


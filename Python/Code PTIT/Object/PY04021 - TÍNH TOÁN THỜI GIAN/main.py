def Minutes(s):
    h, m = s.split(':')
    return int(h) * 60 + int(m)

class Cal_Time:
    def __init__(self, id, name, st, en):
        self.id = id
        self.name = name
        self.minutes = (Minutes(en) - Minutes(st)) % 60
        self.hours =  int((Minutes(en) - Minutes(st)) / 60)

    def __str__(self):
        return f"{self.id} {self.name} {self.hours} gio {self.minutes} phut"

a = []
for _ in range(int(input())):
    cal_time = Cal_Time(input(), input(), input(), input())
    a.append(cal_time)

a.sort(key = lambda x: (-x.hours, -x.minutes))
for x in a:
    print(x)


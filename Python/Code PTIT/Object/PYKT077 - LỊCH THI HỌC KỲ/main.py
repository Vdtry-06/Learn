from datetime import datetime


class Subject:
    def __init__(self, id, name):
        self.id = id
        self.name = name
cnt = 1
class Calendar:
    def __init__(self, id, day, time, group, name):
        global cnt
        self.code = f"T{cnt:03d}"
        self.id = id
        date = day
        self.date = datetime.strptime(date, "%d/%m/%Y")
        self.day = day
        self.time = time
        self.group = group
        self.name = name
        cnt += 1

    def __str__(self):
        return f"{self.code} {self.id} {self.name} {self.day} {self.time} {self.group}"

n, m = list(int(i) for i in input().split())
mp = {}
for _ in range(n):
    subject = Subject(input(), input())
    mp[subject.id] = subject.name
a = []
for _ in range(m):
    id, day, time, group = list(str(i) for i in input().split())
    calendar = Calendar(id, day, time, group, mp[id])
    a.append(calendar)
a.sort(key = lambda x: (x.date, x.time, x.id))
for x in a:
    print(x)
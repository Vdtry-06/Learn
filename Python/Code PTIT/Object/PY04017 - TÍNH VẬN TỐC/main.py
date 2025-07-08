def minutes(s):
    h, m = s.split(":")
    return int(h) * 60 + int(m)

class Competition:
    def __init__(self, name, address, time):
        self.name = name
        self.address = address
        id = ""
        for x in address.split():
            id += x[0]
        for x in name.split():
            id += x[0]
        self.id = id
        v = 120 * 3600 / ((minutes(time) - minutes("6:00")) * 60)
        self.v = v

    def __str__(self):
        return f"{self.id} {self.name} {self.address} {round(self.v)} Km/h"

a = []
for t in range(int(input())):
    competition = Competition(input(), input(), input())
    a.append(competition)
a.sort(key = lambda x: -x.v)
for x in a:
    print(x)
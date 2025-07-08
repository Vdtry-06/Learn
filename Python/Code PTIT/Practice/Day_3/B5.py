from datetime import datetime

tg = [0, 25, 34, 50, 80]

class Customer:
    def __init__(self, id, name, room, come, leave, cost):
        self.id = 'KH{0:0>2}'.format(id)
        self.name = name
        self.room = room
        self.Day0 = str(datetime.strptime(leave, '%d/%m/%Y') - datetime.strptime(come, '%d/%m/%Y')).split()[0]
        if self.Day0 == '0:00:00':
            self.Day0 = 1
        else:
            self.Day0 = int(self.Day0) + 1
        self.sum = tg[int(self.room[0])] * self.Day0 + cost

    def __str__(self):
        return '{} {} {} {} {}'.format(self.id, self.name, self.room, str(self.Day0), str(self.sum))


n = int(input())
a = []
for i in range(n):
    a.append(Customer(i + 1, input(), input(), input().strip(), input().strip(), int(input())))
a.sort(key = lambda k: -k.sum)
print(*a, sep='\n')
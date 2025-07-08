from datetime import datetime

cnt = 1
class Bill:
    def __init__(self, name, room, come, leave, arise):
        global cnt
        self.id = f"KH{cnt:02d}"
        self.name = name
        self.room = room
        self.day = (datetime.strptime(leave.strip(), "%d/%m/%Y") - datetime.strptime(come.strip(), "%d/%m/%Y")).days + 1
        if room[0] == '1': price = 25
        elif room[0] == '2': price = 34
        elif room[0] == '3': price = 50
        elif room[0] == '4': price = 80
        self.price = price * self.day + arise
        cnt += 1

    def __str__(self):
        return f"{self.id} {self.name} {self.room} {self.day} {self.price}"

a = []
for t in range(int(input())):
    bill = Bill(input(), input(), input(), input(), int(input()))
    a.append(bill)
a.sort(key = lambda x: -x.price)
for x in a:
    print(x)

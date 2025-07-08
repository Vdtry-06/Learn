class Apart:
    def __init__(self, id, name):
        self.id = id
        self.name = name

class Employee:
    def __init__(self, id, name, salary, day, code):
        self.id = id
        num = int(id[1]) * 10 + int(id[2])
        if id[0] == 'A':
            if num >= 1 and num <= 3: heso = 10
            elif num >= 4 and num <= 8: heso = 12
            elif num >= 9 and num <= 15: heso = 14
            else: heso = 20
        elif id[0] == 'B':
            if num >= 1 and num <= 3: heso = 10
            elif num >= 4 and num <= 8: heso = 11
            elif num >= 9 and num <= 15: heso = 13
            else: heso = 16
        elif id[0] == 'C':
            if num >= 1 and num <= 3: heso = 9
            elif num >= 4 and num <= 8: heso = 10
            elif num >= 9 and num <= 15: heso = 12
            else: heso = 14
        elif id[0] == 'D':
            if num >= 1 and num <= 3: heso = 8
            elif num >= 4 and num <= 8: heso = 9
            elif num >= 9 and num <= 15: heso = 11
            else: heso = 13

        self.name = name
        self.salary = heso * salary * day * 1000
        self.code = code

    def __str__(self):
        return f"{self.id} {self.name} {self.code} {self.salary}"

n = int(input())
mp = {}
for _ in range(n):
    s = input().split()
    id = s[0]
    name = ' '.join(s[1:])
    apart = Apart(id, name)
    mp[apart.id] = apart.name

m = int(input())
a = []
for _ in range(m):
    id = input()
    employee = Employee(id, input(), int(input()), int(input()), mp[id[3:]])
    a.append(employee)
for x in a:
    print(x)

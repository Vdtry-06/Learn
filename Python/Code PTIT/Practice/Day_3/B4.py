class Student:
    def __init__(self, id, name, classs):
        self.id = id
        self.name = name
        self.classs = classs
        self.p = 10

    def calculation(self, s):
        for c in s:
            if c == 'm':
                self.p -= 1
            elif c == 'v':
                self.p -= 2
        if self.p <= 0:
            self.p = 0

    def result(self):
        print(self.id + " " + self.name + " " + self.classs + " " + str(self.p), end = '')
        if self.p == 0:
            print(" KDDK", end = '')
        print()

m = {}
a = []
t = int(input())

for i in range(t):
    tmp = Student(input(), input(), input())
    m[tmp.id] = tmp
    a.append(tmp)

for i in range(t):
    id, status = input().split()
    m[id].calculation(status)

for i in a:
    i.result()

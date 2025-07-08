class Student:
    def __init__(self, name, sobaidung, soluotnop):
        self.name = name
        self.sobaidung = sobaidung
        self.soluotnop = soluotnop

    def __str__(self):
        return f"{self.name} {self.sobaidung} {self.soluotnop}"

a = []
for _ in range(int(input())):
    name = input()
    c, t = list(int(i) for i in input().split())
    a.append(Student(name, c, t))
a.sort(key = lambda x: (-x.sobaidung, x.soluotnop, x.name))
for x in a:
    print(x)


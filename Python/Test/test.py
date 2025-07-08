class Student:
    def __init__(self, name, address, d1, d2, d3):
        self.name = name
        self.address = address
        mi = min(d1, d2, d3)
        self.avg = (mi + d1 + d2 + d3) / 4

    def __str__(self):
        return f"{self.name} {self.address} {self.avg:.1f}"

a = []
for _ in range(int(input())):
    a.append(Student(input(), input(), float(input()), float(input()), float(input())))

a.sort(key = lambda x: -x.avg)

for x in a:
    print(x)

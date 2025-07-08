class Student:
    def __init__(self, id, name, classes):
        self.id = id
        self.name = name
        self.classes = classes

class Rule:
    def __init__(self, id, data):
        self.id = id
        score = 10
        for x in data:
            if x == 'v': score -= 2
            elif x == 'm': score -= 1
        self.score = score

a = []
t = int(input())
for _ in range(t):
    student = Student(input(), input(), input())
    a.append(student)
b = []
for _ in range(t):
    id, data = list(str(i) for i in input().split())
    rule = Rule(id, data)
    b.append(rule)

for x in a:
    for y in b:
        if x.id == y.id:
            if y.score <= 0:
                print(x.id, x.name, x.classes, 0, "KDDK")
            else:
                print(x.id, x.name, x.classes, y.score)

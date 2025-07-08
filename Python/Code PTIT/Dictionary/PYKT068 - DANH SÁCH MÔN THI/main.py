class Student:
    def __init__(self, id, name, type):
        self.id = id
        self.name = name
        self.type = type

    def __str__(self):
        return f"{self.id} {self.name} {self.type}"

a = []
for t in range(int(input())):
    a.append(Student(input(), input(), input()))
a.sort(key = lambda x : x.id)
for x in a:
    print(x)


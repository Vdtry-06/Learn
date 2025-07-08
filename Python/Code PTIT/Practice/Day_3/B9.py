class Student:
    def __init__(self, id, name, team, school):
        self.id = 'C{:03d}'.format(id)
        self.name = name
        self.team = team
        self.school = school
    def __str__(self):
        return '{} {} {} {}'.format(self.id, self.name, self.team, self.school)

n = int(input())
t = [1]
for i in range(n):
    t.append([input(), input()])
n = int(input())
a = []
for i in range(n):
    name = input()
    team = input()
    a.append(Student(i + 1, name, t[int(team[4::])][0], t[int(team[4::])][1]))
a = sorted(a, key = lambda x: x.name)
for student in a:
    print(student)
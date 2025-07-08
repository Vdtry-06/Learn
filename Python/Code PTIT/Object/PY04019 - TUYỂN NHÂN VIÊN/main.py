cnt = 1
class Recruit:
    def __init__(self, name, theory, practice):
        global cnt

        self.name = name
        self.theory = theory
        self.practice = practice

        self.id = "TS0" + str(cnt)
        if self.theory > 10: self.theory /= 10
        if self.practice > 10: self.practice /= 10
        self.medium = (self.theory + self.practice) / 2

        if self.medium < 5: self.result = "TRUOT"
        elif self.medium < 8: self.result = "CAN NHAC"
        elif self.medium <= 9.5: self.result = "DAT"
        else: self.result = "XUAT SAC"
        cnt += 1

    def getMedium(self):
        return self.medium

    def __str__(self):
        return f"{self.id} {self.name} {self.medium:.2f} {self.result}"

arr = []

for t in range(int(input())):
    name = input()
    theory, practice = float(input()), float(input())
    recruit = Recruit(name, theory, practice)
    arr.append(recruit)

arr.sort(key = lambda recruit: -recruit.getMedium())

for recruit in arr:
    print(recruit)

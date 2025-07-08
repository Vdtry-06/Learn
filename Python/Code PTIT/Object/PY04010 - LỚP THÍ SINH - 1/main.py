class Candidate():
    def __init__(self, name, date, total_a, total_b, total_c):
        self.name = name
        self.date = date
        self.total_a = total_a
        self.total_b = total_b
        self.total_c = total_c
        self.total = total_a + total_b + total_c

    def __str__(self):
        return f"{self.name} {self.date} {self.total:.1f}"


name = input()
date = input()
a = float(input())
b = float(input())
c = float(input())

candidate = Candidate(name, date, a, b, c)
print(candidate)
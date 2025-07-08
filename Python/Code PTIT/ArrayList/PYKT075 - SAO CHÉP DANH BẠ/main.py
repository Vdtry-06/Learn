from sys import stdin
class Directory:
    def __init__(self, day, name, phone):
        day = day.strip().split()
        self.day = ' '.join(day[1:])
        res = ""
        for x in name.split():
            res += x[:1].upper() + x[1:].lower()
            res += " "
        name = res[:-1]
        tmp = name.strip().split()
        self.firstname = tmp[-1]
        self.lastname = ' '.join(tmp[:-1])
        self.name = name
        self.phone = phone


    def __str__(self):
        return f"{self.name}: {self.phone} {self.day}"

try: fr = open('SOTAY.txt', 'r')
except: fr = stdin

lines = list(i.strip() for i in fr if i.strip())
a = []
i = 0
day = lines[0].split()[1]
while i < len(lines):
    if lines[i].startswith("Ngay"):
        day = lines[i]
        i += 1
        while i < len(lines) and not lines[i].startswith("Ngay"):
            name = lines[i]
            phone = lines[i + 1]
            a.append(Directory(day, name, phone))
            i += 2
    else:
        i += 1

a.sort(key = lambda x: (x.firstname, x.lastname))
for x in a:
    print(x)
cnt = 1
class Person:
    def __init__(self, name, type, st, en):
        global cnt
        self.id = f"KH{cnt:02d}"
        res = ""
        for x in name.lower().split():
            res += x[0].upper() + x[1:]
            res += " "
        self.name = res[:len(res) - 1]
        if type == 'A':
            dmuc = 100
        elif type == 'B':
            dmuc = 500
        elif type == 'C':
            dmuc = 200
        sodien = en - st
        if sodien < dmuc:
            tiendinhmuc = sodien * 450
        else:
            tiendinhmuc =  dmuc * 450
        self.tiendinhmuc = tiendinhmuc
        if sodien > dmuc:
            tienvuotdinhmuc = (sodien - dmuc) * 1000
        else:
            tienvuotdinhmuc = 0
        self.tienvuotdinhmuc = tienvuotdinhmuc

        self.thueVAT = tienvuotdinhmuc * 0.05
        self.tongtien = tiendinhmuc + tienvuotdinhmuc + self.thueVAT
        cnt += 1

    def __str__(self):
        return f"{self.id} {self.name} {self.tiendinhmuc} {self.tienvuotdinhmuc} {int(self.thueVAT)} {int(self.tongtien)}"

a = []
for t in range(int(input())):
    name = input().strip()
    type, st, en = input().split()
    person = Person(name, type, int(st), int(en))
    a.append(person)
a.sort(key = lambda x: (-x.tongtien))
for x in a:
    print(x)

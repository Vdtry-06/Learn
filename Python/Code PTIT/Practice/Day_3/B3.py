class CuaRo:
    def __init__(self, name, unit, time) :
        a = [i[0] for i in name.split()]
        b = [i[0] for i in unit.split()]
        self.id = ''.join(b) + ''.join(a)
        self.name = name
        self.unit = unit
        T = time.split(':')
        self.speed = 120 / (int(T[0]) - 6 + int(T[1]) / 60)

    def __str__(self) :
        return '{} {} {} {} Km/h'.format(self.id, self.name, self.unit, round(self.speed))

n = int(input())
cuaRo = []
for _ in range(n) :
    cuaRo.append(CuaRo(input(), input(), input()))
cuaRo = sorted(cuaRo, key = lambda x : -x.speed)
print(*cuaRo, sep = '\n')
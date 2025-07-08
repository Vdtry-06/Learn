class Family:
    def __init__(self, id, name, kind, idx_st, idx_en):
        self.id = 'KH{:02d}'.format(id)
        self.name = name
        self.kind = kind
        self.idx_st = idx_st
        self.idx_en = idx_en
        self.usage = idx_en - idx_st
        self.limit = self.get_limit()
        self.in_limit_cost = min(self.usage, self.limit) * 450
        self.extra_cost = max(0, self.usage - self.limit) * 1000
        self.vat = self.extra_cost // 20
        self.total_cost = self.in_limit_cost + self.extra_cost + self.vat

    def get_limit(self):
        if self.kind == "A":
            return 100
        elif self.kind == "B":
            return 500
        elif self.kind == "C":
            return 200

    def processName(self):
        words = self.name.strip().split()
        return ' '.join(word.lower().capitalize() for word in words)

    def __str__(self):
        return '{} {} {} {} {} {}'.format(self.id, self.processName(), self.in_limit_cost, self.extra_cost, self.vat, self.total_cost)

n = int(input())
families = []

for i in range(n):
    name = input()
    kind, idx_st, idx_en = input().split()
    idx_st, idx_en = int(idx_st), int(idx_en)
    families.append(Family(i + 1, name, kind, idx_st, idx_en))

families.sort(key=lambda x: x.total_cost, reverse=True)

for family in families:
    print(family)

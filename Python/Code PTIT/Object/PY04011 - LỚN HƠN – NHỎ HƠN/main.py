class Compare:
    def __init__(self, ng1, ss, ng2):
        self.ss = ss
        self.ng1 = ng1
        self.ng2 = ng2

        if ss == '>':
            self.ng1 = ng2
            self.ng2 = ng1

mp = {}
t = int(input())
for _ in range(t):
    ng1, ss, ng2 = list(str(i) for i in input().split())
    compare = Compare(ng1, ss, ng2)
    if compare.ng1 is not mp:
        mp[compare.ng1] = 1
    else:
        mp[compare.ng1] += 1
if len(mp) < t:
    print("possible")
else:
    print("impossible")
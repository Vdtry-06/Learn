import re

mp = {}
for t in range(int(input())):
    s = re.findall(r"\b\w+\b", input().lower())
    for x in s:
        if x in mp:
            mp[x] += 1
        else:
            mp[x] = 1

a = sorted(mp.items(), key = lambda x: (-x[1], x[0]))
for x in a:
    print(x[0], x[1])
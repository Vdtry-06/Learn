import re
a = []
for t in range(int(input())):
    for i in [int(x) for x in re.split("[a-zA-Z]", input()) if x != '']:
        a.append(i)
for x in sorted(a):
    print(x)
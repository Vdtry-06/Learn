import re

s = ""
while True:
    try:
        s = input()
        res = []
        arr = re.split(r'[.?!]+', s.lower())
        for x in arr:
            x = ' '.join(x.split())
            if x:
                x = x[0].upper() + x[1:]
                print(x)
    except EOFError:
        break


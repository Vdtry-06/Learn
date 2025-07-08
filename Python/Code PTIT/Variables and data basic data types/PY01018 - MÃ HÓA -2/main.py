P = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."

while True:
    s = input()
    if s == '0':
        break
    k, s = s.split()
    k = int(k)
    res = ""
    for x in s:
        pos = P.find(x)
        res += P[(pos + k) % 28]
    print(res[::-1])
for t in range(int(input())):
    s = list(str(i) for i in input().split())
    res = s[0]
    for i in s[1:]:
        if len(res) + len(i) + 1 > 100:
            break
        res = res + ' ' + i
    print(res)


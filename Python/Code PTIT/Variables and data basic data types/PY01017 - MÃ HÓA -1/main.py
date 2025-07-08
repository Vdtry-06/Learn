for t in range(int(input())):
    s = input()
    d = 1
    res = ""
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            d += 1
        else:
            res += str(d) + s[i - 1]
            d = 1
    res += str(d) + s[-1]
    print(res)
                
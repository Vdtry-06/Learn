def Check(s, i):
    ans = i
    for j in range(i + 1, len(s)):
        if s[j] < s[i]:
            if ans == i:
                ans = j
            elif s[ans] < s[j]:
                ans = j
    if s[ans] < s[i]:
        return ans
    else:
        return -1

for t in range(int(input())):
    s = input()
    n = len(s)
    ans = ""
    for i in range(n - 1, -1, -1):
        index = Check(s, i)
        if index > -1:
            ans = s[:i] + s[index] + s[i + 1: index] + s[i] + s[index + 1:]
            break
    if ans != "" and ans != s and ans[0] != '0':
        print(ans)
    else:
        print(-1)
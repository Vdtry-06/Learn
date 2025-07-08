def Check(s): 
    if len(s) % 2 != 0 or s != s[::-1]: return False
    for x in s:
        if int(x) % 2 != 0: return False
    return True


for t in range(int(input())):
    n = int(input())
    for i in range(22, n, 2):
        if Check(str(i)): print(i, end = ' ')
    print()
            
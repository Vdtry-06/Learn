def Check(s):
    n = len(s)
    for i in range(1, n):
        if(abs(ord(s[i]) - ord(s[i - 1])) != abs(ord(s[n - i]) - ord(s[n - i - 1]))):
            return False
    return True
 
        
for t in range(int(input())):
    s = input()
    if Check(s): print("YES")
    else: print("NO")
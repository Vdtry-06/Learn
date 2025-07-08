s = input()
a = s.split() # tách các từ khỏi " "
x = int(a[0])
y = int(a[2])
z = int(a[4])
if(x + y == z): print("YES")
else: print("NO")

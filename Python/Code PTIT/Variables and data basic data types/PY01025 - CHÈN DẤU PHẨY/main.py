s = input()

d = 0
t = s[::-1]
for i in range(len(t)):
    if i % 3 == 0 and i != 0:
        t = t[:i + d] + "," + t[i + d:]
        d += 1

print(t[::-1])
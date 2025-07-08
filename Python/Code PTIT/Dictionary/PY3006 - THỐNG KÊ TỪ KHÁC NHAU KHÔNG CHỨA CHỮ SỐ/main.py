import re
from collections import Counter

n = int(input())
s, arr = "", []

for _ in range(n):
    s += input().lower() + " "

arr = re.findall(r'[a-z]+', s)
count = Counter(arr)
sorted_count = sorted(count.items(), key = lambda item: (-item[1], item[0]))
for val, cnt in sorted_count:
    print(val, cnt, sep = ' ')

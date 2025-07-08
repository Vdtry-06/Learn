import re
from collections import Counter

n, m = map(int, input().split())
s, arr = "", []

for _ in range(n):
    s += input().lower() + " "

arr = re.findall(r'[a-z0-9]+', s)
count = Counter(arr)
sorted_count = sorted(count.items(), key = lambda item: (-item[1], item[0]))
for val, cnt in sorted_count:
    if cnt >= m:
        print(val, cnt, sep = ' ')

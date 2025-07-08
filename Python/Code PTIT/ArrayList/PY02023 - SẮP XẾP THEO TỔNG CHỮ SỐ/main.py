class process:
    def __init__(self, num, sum):
        self.num = num
        self.sum = sum

def sum_num(n):
    s = 0
    for x in str(n):
        s += int(x)
    return s

for t in range(int(input())):
    n = int(input())
    arr = []
    a = list((int(i) for i in input().split()))
    for i in range(n):
        arr.append(process(a[i], sum_num(a[i])))

    arr.sort(key = lambda x: (x.sum, x.num))

    for x in arr:
        print(x.num, end = ' ')
    print()


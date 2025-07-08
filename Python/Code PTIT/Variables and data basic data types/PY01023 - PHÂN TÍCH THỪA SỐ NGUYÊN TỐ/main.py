import math


for t in range(int(input())):
    n = int(input())
    if n == 1: 
        print(1)
    else:
        res = ""
        for i in range(2, int(math.sqrt(n) + 1)):
            if n % i == 0:
                d = 0
                while n % i == 0:
                    n /= i
                    d += 1
                res += str(i) + "^" + str(d) + " * "
        
        if n > 1:
            res += str(int(n)) + "^" + str(1)
        else: res = res[:len(res) - 3]
        res = "1 * " + res
        print(res) 
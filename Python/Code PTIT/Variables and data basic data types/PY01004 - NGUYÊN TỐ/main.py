import math

def prime(n):
    if(n < 2): return False
    for i in range(2, int(math.sqrt(n)) + 1): # kiểm tra nguyên tố
        if(n % i == 0): return False
    return True

t = int(input())
while(t > 0):
    n = int(input())
    d = 0
    for i in range(1, n):
        if(math.gcd(i, n) == 1):  # hàm ước chung lớn nhất
            d += 1 
            
    if(prime(d)): 
        print("YES")
    else: 
        print("NO")
    t -= 1

    
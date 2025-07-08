test = int(input())

while test > 0:
    
    a = list(int(i) for i in input()) # nhập 1 danh sách
    
    for i in range(len(a) - 1, 0, -1):
        if a[i] >= 5:
            a[i - 1] += 1
        a[i] = 0
    
    if a[0] == 10:
        a[0] = 0
        a = [1] + a # cộng danh sách vd: [9, 9, 9] + [1] = [10, 0, 0]
        
    print(''.join(map(str, a[:])))  # in ra các phần tử trong a
    
    test -= 1
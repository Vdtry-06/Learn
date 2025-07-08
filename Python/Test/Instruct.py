# khai bao các biến trên 1 dòng
a, b, c = map(int, input().split())

# in ra số thập phân sau dấu phẩy
print('%.2f' % a)

# goi ham trong toan hoc
import math
print(math.sqrt(a))

# vong lap
for i in range(1, 10, 1):
    print(i, end = ' ')

# vong while : tuong tu nhu C++

# ham
def prime(a, b):
    res = a + b
    return res
# ham main()
# if __name__ == '__main__':
#     main()

# tao 1 mang
a = []
# them 1 ptu vao list
# a.append(value)
# dao nguoc : reversed(a) 
# or a[::-1] : nhung no se ra : [1, 2, 3, 4]
# doi dai mang : 
len(a)
# vong lap mang
# for i in range(0, len(a))
# them vao chi so bat ki trong list
#  a.insert(vtri, gtri)
# xoa ptu cuoi trong list
a.pop()
# del a[vtri]
# a.remove(gtri)
# xoa tat ca
a.clear()

# a.copy() : noi dung giong 
# a.count(1) : so lan xuat hien cua 1 ptu
# a.index(1) : tra ve chi so dau tien cua 1 ptu
# a.sort() : sap xep
# a.reverse() : lat nguoc
# all() : moi ptu deu True
# any() : True if co it nhat 1 ptu True
# max(), min() :ptu lon nho nhat
# sorted() : da sap xep cua list ban dau
# sum() : tong cac ptu trong list

# vd: a[1, 2, 3, 4, 5]
# a[ _ : _ ] : start and stop
# a[1: 3] : 1, 2
# a[ _ : _ : _ ] : start and stop and step : buoc nhay
# a[1: 4 : 2] : 1, 3

# in ra Hello World
s1 = 'Hello %s' %('World')

# khai bao mang:
a = [int(i) for i in input().split()]

# from math import *
# from sys import stdin
# a = []
# for n in stdin:
#     a += list(map(int, n.split()))
# đọc từng dòng

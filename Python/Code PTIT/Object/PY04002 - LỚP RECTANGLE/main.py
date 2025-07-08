import sys

class Rectangle:
    def __init__(self, high, width, col):
        self.perimeter = (high + width) * 2
        self.area = high * width
        self.color = col.capitalize()

arr = input().split()
if int(arr[0]) > 0 and int(arr[1]) > 0:
    r = Rectangle(int(arr[0]), int(arr[1]), arr[2])
    print('{} {} {}'.format(r.perimeter, r.area, r.color))
else:
    print("INVALID")
sys.exit()

if __name__ == '__main__':
    arr = input().split()
    r = Rectangle(int(arr[0]), int(arr[1]), int(arr[2]))
    print('{} {} {}'.format(r.perimeter(), r.area(), r.color()))
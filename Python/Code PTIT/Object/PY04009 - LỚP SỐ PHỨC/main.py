class Complex:
    def __init__(self, real, img):
        self.real = real
        self.img = img

for _ in range(int(input())):
    arr = list(int(i) for i in input().split())
    a = Complex(arr[0], arr[1])
    b = Complex(arr[2], arr[3])
    real = a.real + b.real
    img = a.img + b.img
    c_real = real * a.real - img * a.img
    c_img = img * a.real + real * a.img
    print(f"{c_real} + {c_img}i," if c_img > 0 else f"{c_real} - {c_img * -1}i,", end = ' ')
    d_real = real * real - img * img
    d_img = 2 * real * img
    print(f"{d_real} + {d_img}i" if d_img > 0 else f"{d_real} - {d_img * -1}i")



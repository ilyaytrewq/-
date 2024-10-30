from random import *

mx = 100000
n = randint(1, mx)
print(n)
for i in range(n):
    if randint(0, 4) < 3:
        print(0, end = ' ')
    else:
        print(randint(-mx // 1, mx // 1), end = ' ')
import os

it = 1
while 1:
    print("Doing test:", it)
    os.system("python gen.py > input.txt")
    os.system("24.exe < input.txt > ans.txt")
    os.system("24_cor.exe < input.txt > cor.txt")
    if int(open('ans.txt').read()) != int(open('cor.txt').read()):
        print("Error on test:", it)
        break
    it += 1
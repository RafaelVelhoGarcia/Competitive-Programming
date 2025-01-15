tot = int(input())
a = int(input())
b = int(input())

c = tot - (a+b)

if (c > a and c > b):
    print(c)

else:  
    if (a > b and a > c):
        print(a)
    else:
        print(b)
c = int(input())
d = int(input())
t= int(input())

res = d/c


if res-t >= 0:
    print("{:.1f}".format(res-t))
else:
    res = 0
    print("{:.1f}".format(res))
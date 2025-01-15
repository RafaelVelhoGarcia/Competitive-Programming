b = int(input())
t = int(input())

if b > t:
    areaf = t*70 + ((b-t)*70)/2
    aream = 70*160 - areaf
else:
    areaf = b*70 + (t-b)*70/2
    aream = 70*160 - areaf

#print(areaf,aream,70*160)
cinco = 70*80
cont = 0
if areaf > cinco:
    cont = 1
if aream > cinco:
    cont = 2
print(cont)


v = int(input())
a = int(input())
f = int(input())
p = int(input())

soma = a+f+p

maior = max(a,f,p)
#print(maior)
menor = min(a,f,p)
#print(menor)

if menor <= a <= maior:
    meio = a
if menor <= f <= maior:
    meio = f
if menor <= p <= maior:
    meio = p


if soma <= v:
    print(3)
else:
    if a > v and f > v and p > v:
        print(0)
    else:
        if (v - menor) > meio and (v - menor) < maior:
            print(2)
        
        else:
            print(1)
    




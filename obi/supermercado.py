n = int(input())

for c in range (n):
    a,b = input().split()
    
    a = float(a)
    b = int(b)
     
    val = 1000/b
    res = a*val
    if c == 0:
        menorval = res
    
    if res < menorval :
        menorval = res
        
print( "{:.2f}".format(menorval))
    
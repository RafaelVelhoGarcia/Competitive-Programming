t = int(input())

for cont in range(t):
    a,b = map(int,input().split())
    
    a = (9*(a)/5.0) + 32
        
    res = a+b
    
    res = 5*(res-32)/9.0
    print(f"case {cont+1}: {res:.2f}")

from datetime import datetime

t = int(input())

nametnum = {}

nametnum['January'] = 1

nametnum['February'] = 2

nametnum['March'] = 3

nametnum['April'] = 4

nametnum['May'] = 5
nametnum['June'] = 6
nametnum['July'] = 7
nametnum['August'] = 8
nametnum['September'] = 9
nametnum['October'] = 10
nametnum['November'] = 11
nametnum['December'] = 12

for i in range(t):
    entrada = input().split('-')
    
    entrada[0] = int(entrada[0])
    entrada[2] = int(entrada[2])
    print(nametnum[entrada[1]] )
    print(entrada)
    
    data = datetime(year = entrada[0] ,month =  nametnum[entrada[1]] , day = entrada[2])
    dcont = 0
    n = int(input())
    print("esse :")
    print(n)
    datares = data + datab
    
    print(datares)
    
    
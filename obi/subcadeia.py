n = int(input())


tam = []
lista = []
entrada = input()

palin = []

lista = list(entrada)

invertida = entrada[::-1]

#print(entrada)
#print(invertida)

for i in range(n):
    palavra = ''
    palavrab = ''
    for j in range(i,n):
        palavra += entrada[j]
        if n - j > 0:
            index = n-j -1
            #print(index)
        else :
            index = 0
        palavrab += invertida[index]
        #print(palavra)
        #print("-=-=-=-=-=")
        #print(palavrab)
        
        inv = palavrab[::-1]
        
        if palavra == palavrab:
            '''print("palavra")
            print(palavra)
            print("inv")
            print(inv)
            print("palin")'''
            inv = palavra[::-1]
            if palavra == inv:
                palin.append(palavra)
                tam.append(len(palavra))
#print(palin)
#print(tam)

maior = 0
for i in range(len(tam)):
    num = int(tam[i])
    if num > maior:
        maior = num
        pos = int(i)

print(len(palin[pos]))


'''
maximize o número resultante de pedaços separados pelo corte.


é o numero q eles estao em media abaixo

20 5 10 5 15 15 15 5 6 22 = 123
40 50 33 = 123

123/10 = 12,3 

'''

n = int(input())

lista = []
media = 0
cont = 0

lista = input().split()

for c in range (n):
    a = int(lista[c])
    
    media += a
    
media = media//n

#print(media)

for c in range(n):
    b = int(lista[c])
    
    if b > media:
        cont += 1
print(cont)
    
    
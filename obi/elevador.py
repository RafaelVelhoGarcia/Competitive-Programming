'''  Sobe a caixa de peso 4, desce a outra cabine vazia; (diferença de 4) - subiu 4 
Sobe a caixa de peso 10, desce a caixa de peso 4; (diferença de 6) - subiu 10 desceu 4
Sobe a caixa de peso 15, desce a caixa de peso 10; (diferença de 5) subiu 15 desceu 10 (só 15 em cima)
Sobe a caixa de peso 4, desce a outra cabine vazia; (diferença de 4) subiu 4 desceu vazia (ficou 15 e 4 lá em cima , 10 aqui em baixo)
Sobe a caixa de peso 10, desce a caixa de peso 4; (diferença de 6) subiu (sobe 10 desce 4)
Sobe a caixa de peso 4, desce a outra cabine vazia. (diferença de 4) '''
'''           
    ordena a lista
    menor sobe < 8
    segundo maior sobe menor desce < 8
    terceiro maior sobe e segundo menor desce < 8
    conseguimos deixar o maior lá me cima
    -=-=-=-=-=-
    menor sobe 
    segundo maior sobe menor desce 
    segundo maior ficou lá em cima
'''

'''
14 10 23 20


sobe 10 desce vazio
sobe 14 desce 10
sobe 20 desce 14
sobe 23 desce 20
fica 23

sobe 


'''



n = int(input())

lista = []

lista = input().split()

for i in range(0,n):
    lista[i] = int(lista[i])



lista.sort()

flag = False
for i in range(0,n):
    menor = lista[0]
    if menor > 8 :
        flag = True
        break
    
    atual = lista[i]
    ant = lista[i-1]
    peso = 0
    if i > 0:    
        peso = abs(atual - ant)
    
    if peso > 8:
        flag = True
        break
       
if flag == True:
    res = "N"
else:
    res = "S"
    
print(res)
    
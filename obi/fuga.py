'''
Toda célula (i, j) onde i e j são pares contém um armário.
 A sala tem uma entrada na célula (Xe, Ye) e uma saída na célula (Xs, Ys), que ficam em posições diferentes nas bordas da sala.
A entrada e a saída nunca são vizinhos a um armário.

derrubar armários da sala, de forma a aumentar o tamanho do percurso necessário para ir da entrada até a saída. 

posição (i, j) da sala, ao cair irá ocupar uma das seguintes opções:

    As células (i, j) e (i, j + 1);
    As células (i, j) e (i, j - 1);
    As células (i, j) e (i + 1, j); ou
    As células (i, j) e (i - 1, j). 

você deve encontrar uma forma de derrubar os armários tal
a distância entre a entrada e a saída da sala seja
****a maior possível**** dentre todas as formas de derrubar os armários. 
=-=-=-=-=-=-
derrubar armarios e deixa ro caminho maior possivel

arma sempre i e j par

caminho mais rapido é o tudo reto

caminho mais rapifo = entrada j até j da saida i da entrada ate i da saida 

agr eu atrapalho o caminho mais rapido sempre tampando os caminhos diretos 
'''

'''
** derrubar armarios ***
se entra da é mais pra cima( n/2 ) rampa a saida de cima

faça ele descer tudo reto para baixo

de prefenrenci dele subir tudo reto pra cima em direção oposta


codigo :

    if f > n//2 entao
        UmMaisProx = i-1 j-1
        matriz[i-1][j] = 1
        
    else:
        UmMaisProx = i+1 j-1
        matriz[i+1][j] = 1

desce tudo reto

 coluna f -1
 combinado com todos os i impares menos o i == n ou i == 1 o resto vira 1	
 
 todos menos o Ummaisproximo viram 1 na direcao oposta do UmMaisProximo

agr isso ao contrario 

'''


def printmat ():
    for i in range (1,tam):
        print(matriz[i])



n,m = input().split()

n = int(n)

m = int(m)

tam = n+1

matriz = [0] * tam

for c in range (1,tam):
    matriz[c] = [0] * tam
for i in range (1,tam):
    #print(matriz[i])
    for j in range (1,tam):
        if i % 2 == 0 and j % 2 == 0:
            matriz[i][j] = 1
        else:
            matriz[i][j] = 0

for i in range (1,tam):
    print(matriz[i])
print("xxxxxxxxxxxxxxxx")



# entrada da saida e da entrada

e,f = input().split()

e = int(e)

f = int(f)


s,r = input().split()

s = int(s)

r = int(r)
matriz[e][f] = 2
matriz[s][r] = 2

for i in range (1,tam):
    print(matriz[i])
print("xxxxxxxxxxxxxxxx")


if e >= n//2 :
    matriz[e-1][f] = 8
    matriz[e][f-1] = 8
    dois = 2
    colunaAtual = f-1
    for c in range(1,tam):
        if e + dois != n:
            matriz[e+dois][colunaAtual] = 8
            dois += 2
    
    colunaAtual = f-3
    linhaatual = n
    
    for c in range(1,tam):
        if linhaatual != 1:
            matriz[linhaatual][colunaAtual] = 8
        linhaatual -= 2
        
    colunaAtual = f - 5
    dois = 2
    for c in range(1,tam):
        if e + dois != n:
            matriz[e+dois][colunaAtual] = 8
            dois += 2
    
else:
    
    matriz[e+1][f] = 8
    dois = 2
    for c in range(1,tam):
        if e+ dois != n:
            matriz[e-dois][f-1] = 8
            dois += 2


for i in range (1,tam):
    print(matriz[i])
print("xxxxxxxxxxxxxxxx")

    
''' as únicas mensagens que Sara envia são respostas a mensagens que ela recebeu.
    Sara envia no máximo uma mensagem como reposta a uma mensagem que recebeu.
    um amigo de Sara nunca envia uma nova mensagem para Sara até que tenha recebido resposta da mensagem que enviou anteriormente. '''

''' 
    R X indica que uma mensagem foi recebida do amigo X.
    E X indica que uma mensagem foi enviada ao amigo X. '''

'''T X indicando que X segundos se passaram entre o evento anterior e o evento posterior a esse registro.'''
#Se não há registro do tipo T X entre dois registros de eventos consecutivos significa que exatamente 1 segundo se passou entre esses dois eventos.

'''R2R3T5E2E3
r= 0
e = 1
2 3
[0][99]
[0][0]
[0][5]
[1][0]
   [1]
'''


'''Dada a lista de registros do aplicativo de Sara, sua tarefa é determinar o Tempo de Resposta Total para cada amigo.'''
cont = 0
nrepetidos = []
matriz=[0]*110
temp = 0
conttemp = 0

for j in range(1,110):
    matriz[j] = [0]*500


n = int(input())

for i in range(n):
    temp +=1
    v, x = input().split()
    v = v
    x = int(x)
    if v == 'R':
        matriz[x][temp] = 1
        if x not in nrepetidos:
            nrepetidos.append(x)
    elif v == 'E' :
        matriz[x][temp] = 1
        if x not in nrepetidos:
            nrepetidos.append(x)
    else:
        matriz[x][i] = -x
        temp += x-1
    print(temp)

nrepetidos.sort()



for num in nrepetidos:
    print(matriz[num])
pos = 0
for i in nrepetidos:
    flag = False
    soma = 0
    num = i;
    if num in nrepetidos:
        for j in range(1,n+temp):
            cont += 1
            print(f"temp cont é {conttemp}")
            if conttemp % 2 == 1:
                flag = True 
            var = matriz[i][j]
            if var == 1 :
                if conttemp == 0:
                    pos = j
                    print(f"posicao temporarai {pos} de {num}")
                else:
                    temppos = j
                    soma += temppos - pos
                    print(f"posicao temporarai {j} de {num}" )
                    pos = temppos
                    #print(pos)
                    
                conttemp += 1
    print(f"essa é a soma{soma}")
    cont = soma
    if flag == True :
        result = cont - conttemp + 1
        print(f"{i} {result}")
    else:
        print("atuamalca")
        print(f"{i} {-1}")
    cont =0
    conttemp = 0
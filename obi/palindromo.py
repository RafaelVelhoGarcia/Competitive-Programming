#10
#bb0a0bcb0baab
#bbabcbbaab
#CONTa os zero mais 1
''' bb bab bcb baab bb  aa 

    primeira varrida{


    }
    ida -- bb bab bcb bb baab
    -- escolhe o maior 
    coloca zero no primeiro - 1 e n ultimo menos + 1
    *adiciona em uma lista vazia
    ignore o ultimo b na contagem    
    #bbabcb0baab0
    -- cria uma lista sem eles
    #bbabcb
    verifica se o segundo maior ta na lista 
    se sim
    remova ele e coloca zero onde ele aparece
    coloca zero no primeiro - 1 e n ultimo menos + 1
    #bba0bcb0baab0
    #bba
    verifica se o segundo maior ta na lista 
    se sim
    remova ele e coloca zero onde ele aparece
    coloca zero no primeiro - 1 e n ultimo menos + 1
    #0bb0a0bcb0baab0
    #a
    if tamanho de lista = 1 break;

    print(tamLista - 1)
    '''
'''
entradas:
entradas []
lista de posicoes de letras iguais 
26 listas



 1 entra entrada 
 2 vare a entrada
 {salva primeira letra 
 salva todas posisocoesaa  das letras igual a primeira letra } 
cria strings de [primeira até pos salvas]
if string= string.reverse() 
    salva elas na lista de palindromo 
    remove da lista default 



'''


n = int(input())
entrada = [ ]
entrada = input()
entradacopia = entrada[::]

tamanho = len(entrada)
listaPos = []
palindromos = []

cont = 0
while (cont < tamanho):
    #print(cont)
    letra = entrada[cont]
    #print(letra)
    for c in range (cont,tamanho):
        if c != 0:
            #print (entrada)
            #print (letra)
            if entrada[c] == letra:
                #print("foi igual:")
                pos = c
                #print(pos)
                listaTemp = []
                listaTemp = entrada[cont:pos+1]
                #print("lista temp 0000000")
                #print(listaTemp)
                reverse = []
                reverse = listaTemp[::-1]
                
                if (reverse == listaTemp):
                    palindromos.append(listaTemp)
                    if cont == 0:
                        maior = len(listaTemp)
                        print("maior de todos")
                        print(maior)
                    if len(listaTemp) > maior:
                        maiorPalindromo = listaTemp
                        posI = cont
                        posF = pos
    
    print(palindromos)
    cont +=1
print(maiorPalindromo)
print(entrada)
print(posI)
print(posF)
print(entrada)

t =int(input())
mapa = {}
times = []
entra = []
resp = {}
usados = []
for y in range(t):
    entra.clear()
    mapa.clear()
    entra.clear()
    usados.clear()
    n= int(input())
    
    for i in range(1,n+1):
        entrada = input().split()
        lista = list(entrada)
        nome = lista[0]
        lista.pop(0)
        mapa[nome] = lista
#print(mapa)
    for c in range(1,n+1):
        atual = int(i)
        entra = list(input().split())
        for time in entra:
            sala = time
            cor = mapa[time]
            #print("!!!")
            #print(cor)
            for j in range(n):
                nomeAtual = entra[0]
                num = int(cor[j])
                if c == num:
                    #print(f"Eu quero o nome {sala}")
                    prioridade = j+1
                    #print(f"sou o time {c} e o nome {sala} me da a prioridade a de nivel{prioridade} ")
                    #print(j+1)
                    #print("_+_+_+_+_=-=_+_")
                    #print(usados)
                    if prioridade == n:
                        #print("PERDI")
                        continue
                    else:
                        imp = int(j+1)
                        if prioridade == c:
                            #print("arrasou")
                            if sala not in usados:
                                resp[c] = sala
                                usados.append(sala)
                        elif c < n and prioridade == 1:
                            if sala not in usados:
                                resp[c] = sala
                                usados.append(sala)
                                #print("&*&*&*&*&*&*")
    #print("-=-=-"*30)
    #print("-=-=-"*30)
    #print(resp)
    flag = False
    for i in range(n):
        a = entra[i]
        #print(a)
        #print("usado:")
        #print(usados)
        if a not in usados:
            flag = True
            naousado= a
    
    if flag == True:
        for i in range(1,len(resp)+1):
            print(resp[i])
        print(naousado)
        break
    
    else:
        print("entour")
        for i in range(1,len(resp)+1):
            print(resp[i])
        print(entra[n-1])
        

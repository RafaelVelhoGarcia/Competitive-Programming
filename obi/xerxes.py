'''O número N será sempre ímpar, para não haver empate na partida. Vamos também considerar
que os jogadores nunca escolhem a mesma mão numa rodada, para não haver empate na rodada.
Você deve escrever um programa que determine quem venceu a partida, se foi dario ou xerxes. '''

n = int(input())
contx = 0
contd = 0


for c in range (n):
    d,x = input().split()
    
    d = int(d)
    x = int(x)
    
    if d == 0:
        if x == 3:
            contx +=1
        elif x == 4:
            contx +=1
        elif x ==1:
            contd +=1
        elif x == 2:
            contd +=1
    elif d == 1:
        if x == 0:
            contx +=1
        elif x == 4:
            contx +=1
        elif x ==2:
            contd +=1
        elif x == 3:
            contd += 1
    elif d == 2:
        if x == 0:
            contx +=1
        elif x == 1:
            contx +=1
        elif x ==3:
            contd +=1
        elif x == 4:
            contd +=1
    elif d == 3:
        if x == 2:
            contx +=1
        elif x == 1:
            contx +=1
        elif x ==4:
            contd +=1
        elif x == 0:
            contd +=1
    elif d == 4:
        if x == 2:
            contx +=1
        elif x == 3:
            contx +=1
        elif x == 0:
            contd +=1
        elif x == 1:
            contd +=1
if contd > contx:
    print("dario")
else:
    print("xerxes")


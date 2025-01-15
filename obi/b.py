n = int(input())
lista = list(map(int, input().split()))

a, b = map(int, input().split())
al = 999
# Inicialização dos vetores e cálculo de dados
bb = [0] * n
cc = [0] * n
somaimpar = 0

for i in range(n):
    bb[i] = lista[i] % 2
    cc[i] = lista[i] % 2
    somaimpar += bb[i]

# Verificar se é possível balancear as maracas
if somaimpar % 2 != 0:
    al = -1

# Funções para encontrar a posição mais próxima com 1
def maispertoR(x):
    for i in range(1, n):
        pos = (x + i) % n
        if bb[pos] == 1:
            return i
    return -1

def maispertoL(x):
    for i in range(1, n):
        pos = (x - i + n) % n
        if bb[pos] == 1:
            return i
    return -1

def maispertoRb(x):
    for i in range(1, n):
        pos = (x + i) % n
        if cc[pos] == 1:
            return i
    return -1

def maispertoLb(x):
    for i in range(1, n):
        pos = (x - i + n) % n
        if cc[pos] == 1:
            return i
    return -1

# Calcular o custo de redistribuição do início ao fim
cont = 0
for i in range(n):
    if bb[i] == 1:
        print(f"sou o {i+1}")
        direita = maispertoR(i)
        esquerda = maispertoL(i)
        if direita == -1 or (esquerda != -1 and esquerda * a < direita * b):
            if esquerda != -1:
                bb[(i - esquerda + n) % n] = 0
                cont += esquerda * a
                print("coisei: com :")
                print(esquerda)
        else:
            if direita != -1:
                bb[(i + direita) % n] = 0
                cont += direita * b
                print("coisei: com :")
                print(direita)

# Calcular o custo de redistribuição do fim ao início
contb = 0
for i in range(n - 1, -1, -1):
    if cc[i] == 1:
        direita = maispertoRb(i)
        esquerda = maispertoLb(i)
        if direita == -1 or (esquerda != -1 and esquerda * a < direita * b):
            if esquerda != -1:
                cc[(i - esquerda + n) % n] = 0
                contb += esquerda * a
        else:
            if direita != -1:
                cc[(i + direita) % n] = 0
                contb += direita * b

# Imprimir o menor custo encontrado

if al == -1:
    print(-1)
else:
    print(min(cont, contb))

n = int(input())
lista = list(map(int, input().split()))

a, b = map(int, input().split())
al = float('inf')  # Usar infinito para comparação de menor valor
bb = [0] * n
cc = [0] * n
somaimpar = 0

# Inicialização dos vetores e cálculo de dados
for i in range(n):
    bb[i] = lista[i] % 2
    cc[i] = lista[i] % 2
    somaimpar += bb[i]

# Verificar se é possível balancear as maracas
if somaimpar % 2 != 0:
    print(-1)
    exit()

def maispertoR(x):
    if x == n-1 and bb[0] == 1:
        return 9999
    for i in range(1, n):
        pos = (x + i) % n
        if bb[pos] == 1:
            return i
    return -1

def maispertoL(x):
    if x == 0 and bb[n-1] == 1:
        return 9999
    for i in range(1, n):
        pos = (x - i + n) % n
        if bb[pos] == 1:
            return i
    return -1

def maispertoRb(x):
    if x == n-1 and cc[0] == 1:
        return 9999
    for i in range(1, n):
        pos = (x + i) % n
        if cc[pos] == 1:
            return i
    return -1

def maispertoLb(x):
    if x == 0 and cc[n-1] == 1:
        return x
    for i in range(1, n):
        pos = (x - i + n) % n
        if cc[pos] == 1:
            return i
    return -1

# Calcular o custo de redistribuição
cont = 0
for i in range(n):
    if bb[i] == 1:
        direita = maispertoR(i)
        esquerda = maispertoL(i)
        if direita == 9999:
            cont += b
            bb[i] = 0
            bb[0] = 0
            continue
        if esquerda == 9999:
            cont += a
            bb[i] = 0
            bb[n-1] = 0
            continue
        if direita == -1 or (esquerda != -1 and esquerda * a < direita * b):
            if esquerda != -1:
                bb[(i - esquerda + n) % n] = 0
                cont += esquerda * a
        else:
            if direita != -1:
                bb[(i + direita) % n] = 0
                cont += direita * b
        bb[i] = 0

contb = 0
for i in range(n - 1, -1, -1):
    if cc[i] == 1:
        direita = maispertoRb(i)
        esquerda = maispertoLb(i)
        if direita == 9999:
            contb += b
            cc[i] = 0
            cc[0] = 0
            continue
        if esquerda == 9999:
            contb += a
            cc[i] = 0
            cc[n-1] = 0
            continue
        if direita == -1 or (esquerda != -1 and esquerda * a < direita * b):
            if esquerda != -1:
                cc[(i - esquerda + n) % n] = 0
                contb += esquerda * a
        else:
            if direita != -1:
                cc[(i + direita) % n] = 0
                contb += direita * b
        cc[i] = 0

# Imprimir o menor custo encontrado
print(min(cont, contb))

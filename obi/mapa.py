lista = []

def limite(l, c):
    if 0 <= l < L and 0 <= c < C:
        return True
    return False

def anda(l, c):
    for i in range(4):
        ll = l + dl[i]
        cc = c + dc[i]
        if limite(ll, cc) and matriz[ll][cc] == 'H':
            lista.append((ll, cc))
            matriz[l][c] = '.'  # Marca a posição anterior como visitada
            anda(ll, cc)
            break  # Após encontrar o caminho, não precisamos verificar outras direções

dl = (0, 0, -1, 1)
dc = (1, -1, 0, 0)

L, C = map(int, input().split())
matriz = []

for _ in range(L):
    matriz.append(list(input()))

# Encontrar a posição inicial 'o'
for i in range(L):
    for j in range(C):
        if matriz[i][j] == 'o':
            xi, yi = i, j
            break

# Iniciar a busca pelo caminho de Hermione
anda(xi, yi)

# A última posição na lista será a posição atual de Hermione
pos_atual = lista[-1]
print(pos_atual[0] + 1, pos_atual[1] + 1)

def tempo_minimo_para_balancear(N, maracas, A, B):
    total_mi = sum(maracas)
    
    # Verificar se o total de maracas é par
    if total_mi % 2 != 0:
        return -1
    
    excedente = [0] * N
    deficiencia = [0] * N
    custo_total = 0
    
    # Calcular excedente e deficiência
    for i in range(N):
        # Calcular excedente e deficiência
        requerido = maracas[i] // 2
        if maracas[i] > requerido:
            excedente[i] = (maracas[i] - requerido) // 2
        elif maracas[i] < requerido:
            deficiencia[i] = (requerido - maracas[i]) // 2
    
    # Usar uma abordagem gananciosa para balancear os excedentes e deficiências
    # Percorrer a lista e balancear as posições
    excedente_atual = 0
    deficiencia_atual = 0
    
    for i in range(N):
        excedente_atual += excedente[i]
        deficiencia_atual += deficiencia[i]
        
        if excedente_atual > 0:
            custo_total += excedente_atual * A
        if deficiencia_atual > 0:
            custo_total += deficiencia_atual * B
    
    return custo_total

# Exemplo de uso:
N = int(input())
maracas = list(map(int, input().split()))
A, B = map(int, input().split())

print(tempo_minimo_para_balancear(N, maracas, A, B))

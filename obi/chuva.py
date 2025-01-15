dx = (0,0,1,-1)
dy = (1,-1,0,0)

def limite(x,y):
    return x >= 0 and y >= 0 and x < n and y < m
def dfs(i,j):
    print(i,j)
    if i == 6 and j == 8:
        print("88**&*&*&*&*&*")
    if (vis[i][j] != 1):
        vis[i][j] = 1
        matriz[i][j] = 'o'
        if limite(i+1,j+1):
                if matriz[i+1][j] == '.' and limite(i+1,j)  and vis[i+1][j] != 1 and matriz[i+1][j] != '#':
                    vis[i][j+1] = 1
                    vis[i][j-1] = 1
                    dfs(i+1,j)
                if  matriz[i - 1][j] == 'o' and limite(i-1,j)  and vis[i-1][j] != 1 :
                    dfs(i+1,j)
                if (matriz[i][j-1] == '.' and  matriz[i + 1][j-1] == '#' and limite(i,j-1) and vis[i][j-1] != 1 ):
                    dfs(i,j-1)
                if (matriz[i][ j + 1] == '.' and matriz[i+ 1][j + 1] == '#' and limite(i,j+1) and vis[i][j+1] != 1):
                    dfs(i,j+1)
                if(matriz[i+1][j] == '#' and matriz[i-1][j+1] == '.' and limite(i,j+1) and vis[i][j+1] != 1):
                    dfs(i,j+1)
                if(matriz[i+1][j] == '#' and matriz[i-1][j-1] == '.' and limite(i,j-1) and vis[i][j-1] != 1):
                    dfs(i,j-1)
                if (matriz[i][j-1] == '.' and matriz[i+1][j] == '#'and limite(i,j-1) and vis[i][j-1] != 1):
                    dfs(i,j-1)
                if (matriz[i][j+1] == '.' and matriz[i+1][j] == '#'and limite(i,j+1) and vis[i][j+1] != 1):
                    dfs(i,j+1)
                if (matriz[i+1][j] == '.' and matriz[i+1][j-1] == '#'):
                    dfs(i+1,j)
n,m = map(int,input().split())

matriz = [None] * n
vis = [0] * n

for i in range(n):
    vis[i] = [0] * m 


for i in range(n):
    matriz[i] = list(input())

y = x= 0
for j in range(m):
    x = 0
    if matriz[0][j] == 'o':
        y = j
print(x,y)
dfs(x,y)




for i in range(n):
    print(matriz[i])
for linha in matriz:
    print(''.join(linha))
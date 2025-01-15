n = int(input())
A= input()

m = int(input())

B = input()


menor = min(n,m)
y = B[::-1]
print(B,y)


cont = 0
for i in range(menor):
    if i == len(palavra1) or i == len(palavra2):
        break
    if A[i] == B[i]:
        cont +=1
print(cont)
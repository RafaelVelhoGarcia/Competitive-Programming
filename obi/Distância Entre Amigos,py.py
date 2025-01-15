n = int(input())
p = list(map(int,input().split()))

dist0 = 0
k = -1

for i in range(n):
    d0i = p[0] + i + p[i]
    if d0i > dist0:
        dist0 = d0i
        k = i
maxdist = 0

for i in range(n):
    if i != k:
        maxdist = max(maxdist,p[k] + abs(k-i) + p[i])

print(maxdist)
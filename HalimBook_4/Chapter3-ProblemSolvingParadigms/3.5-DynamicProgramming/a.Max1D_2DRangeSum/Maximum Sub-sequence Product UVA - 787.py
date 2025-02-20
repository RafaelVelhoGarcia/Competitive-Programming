while True:
    try:
        x = list(map(int,(input().split())))
        x.pop()
        tam = len(x)
        ans = x[0]
        for i in range (tam):
            prod = 1
            for j in range(i,tam):
                prod *= x[j]
                ans = max(prod,ans)
        print(ans)
    except EOFError:
        break
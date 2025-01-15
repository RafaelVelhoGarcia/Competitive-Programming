while True:
    matriz[0] * 8
    
    for i in range(8):
        matriz[i] = [0]*8
    
    res = 8
    xi,yi,xf,yf = input().split()
    xi= int(xi)
    xf = int(xf)
    yi = int(yi)
    yf = int(yf)
    if xi == 0 and xf == 0 and yi ==0 and yf ==0:
        break
    xx = (0,0,1,-1)
    yy = (1,-1,0,0)
    
    
    dx = (1,-1,1,2,-2,2,3,3,-3,4,4,-4,5,5,-5,6,-6,6,7,-7,7,8,-8,8)
    dy = (-1,1,1,2,2,-2,3,-3,3,4,-4,4,5,-5,5,6,6,-6,7,7,-7,8,8,-8)
    
    for c in range (24):
            #print("esse")
            a = xi + dx[c]
            b =yi + dy[c]
            
            matriz[a][b] += 1
            if a > 8 or b > 8 or a < 1 or b < 1:
                continue
            
            #print("esse")
            #print(a)
            #print(b)
            if (xi + dx[c] == xf) and (yi + dy[c] == yf):
                #print("4732842483248389239823892348923478942378924")
                res = 1
                break;
            
            
            
    if xi == xf or yi == yf:
        res = 1
    if xi ==xf and yi ==yf:
        res = 0
    
    if res == 8:
        res = 2
    for c  in range(8):
        
        print(matriz[])
    
    print(res)
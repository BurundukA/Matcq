for i in range(123456789, 223456789+1):
    k = 0
    d = 2
    maxd = 0
    if int(i**0.5)== i**0.5:
        while  d < i**0.5:
            if i%d == 0:
                k +=2
                if maxd == 0:
                    maxd = i // d
            d+=1
        if d*d == i:
            k +=1
            if k ==0:
                print(s, k, maxd)

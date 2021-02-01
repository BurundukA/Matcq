a = []
mas = []
kolh = 0
kol = 0
h = 0
for x in range(2095, 19402):
    d = 2
    while x % d != 0:
        d+=1
    if d == x:
        a.append(x)
        p = x
        mas = []
        while p > 0:
            mas.append(p % 10)
            kolh = kolh + 1
            p = p // 10
        #print(mas)
        if mas[0]< mas[kolh-1]:
            #print(x)
            kol = kol + 1
            if mas[0]==1 and mas[1] == 2:
                l = x
        kolh = 0
        mas.clear()
print(kol)
print(l)
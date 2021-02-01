kolh = 0
kols =0
kol = 0
for i in range(1082, 129932):
    p = i
    mas = []
    while p > 0:
        mas.append(p % 10)
        p = p // 10
    if i < 9999:
        if (mas[3] > mas[2]) and (mas[2] > mas[1]) and (mas[1] > mas[0]):
            for j in range(1, i):
                if i % j == 0:
                    kols = kols + 1
            kols = kols + 1
            if kols % 3 == 0:
                kol = kol + 1
                if mas[3] == 7:
                    l = i
            kols = 0

    if (i < 99999) and (i >9999):
        if mas[4]>mas[3] and mas[3]>mas[2] and mas[2]>mas[1] and mas[1]>mas[0]:
            for j in range(1, i):
                if i % j == 0:
                    kols = kols + 1
            kols = kols + 1
            if kols % 3 == 0:
                kol = kol + 1
                if mas[4] == 7:
                    l = i
            kols = 0

    if i > 99999:
        if mas[5]>mas[4] and mas[4]>mas[3] and mas[3]>mas[2] and mas[2]>mas[1] and mas[1]>mas[0]:
            for j in range(1, i):
                if i % j == 0:
                    kols = kols + 1
            kols = kols + 1
            if kols % 3 == 0:
                kol = kol + 1
                if mas[5] == 7:
                    l = i
            kols = 0
    mas.clear()

print(kol)
print(l)
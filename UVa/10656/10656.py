n = int(input())
while n != 0:
    printed = False
    maxc = None   
    for i in range(n):
        c = int(input())
        if maxc == None or maxc < c:
            maxc = c 
        if 0<c:
            if printed:
                print(" ", end='')
            printed = True
            print(c, end='')
    if not printed:
        print(maxc, end='') 
    print()
    n = int(input())

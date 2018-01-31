t,k = map(int, input().split())

choose_s = [[None for x in range(10001)] for y in range(10001)] 

save = [None]*100001

def choose(i,j):

    if i < j:
        return 0

    if i == 0:
        return 1
    
    if j == 0:
        return 1
    
    if j == i:
        return 1

    global choose_s

    if choose_s[i][j] is None:
       
        choose_s[i][j] = choose(i-1,j-1) + choose(i-1, j)

    return choose_s[i][j]

for c in range(t):

    a,b = map(int, input().split())

    for i in range(a,b+1):

        if save[i] is None:

            save[i] = 0

            for j in range(0, i//k+1):

                save[i] += choose(i,j)



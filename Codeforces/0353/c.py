n = int(input())
a = list(map(int, input().split(" ")))[::-1]
m = input()[::-1]

sumall = [0]*(n+1)
for x, ai in enumerate(reversed(a)):
    i = n-1 - x
    sumall[i] = sumall[i+1]+ai

summ = [0]*(n+1)
for i, ai in enumerate(a):
    summ[i] = summ[i-1]
    if(m[i] == '1'):
        summ[i] += ai

maxval = summ[n-1]

for i in range(n):
    
    if m[i]== '1' and maxval < summ[i-1] + sumall[i+1]:
        maxval = summ[i-1] + sumall[i+1] 

    #print(m[i], a[i], summ[i], sumall[i], summ[i-1] + sumall[i+1], maxval)

print(maxval)

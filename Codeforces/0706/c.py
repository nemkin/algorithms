import sys

n = int(input())
c = list(map(int, input().split()))
strings = [input() for i in range(n)]
revstrings = [strings[i][::-1] for i in range(n)]
maxc = sum(c)+1

d = [[maxc,maxc] for i in range(n)]

d[0][0] = 0
d[0][1] = c[0]

for i in range(1,n):
    if strings[i-1] <= strings[i]:
        d[i][0] = d[i-1][0] 

    if revstrings[i-1] <= strings[i]:
        d[i][0] = min(d[i][0], d[i-1][1])

    if strings[i-1] <= revstrings[i]:
        d[i][1] = d[i-1][0] + c[i] 

    if revstrings[i-1] <= revstrings[i]:
        d[i][1] = min(d[i][1], d[i-1][1] + c[i])

result = min(d[n-1][0],d[n-1][1])

if result == maxc:
    print(-1)
else:
    print(result)

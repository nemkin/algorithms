from math import gcd

n = int(input())
a = list(map(int, input().split(" ")))

dp = [[0, 0] for i in range(n)]
allmul = [0 for i in range(n)]

dp[0][0] = 0
dp[0][1] = a[0]
allmul[0] = a[0]

edges = [[]]*n

for i in range(n-1):

    x, y = map(int, input().split(" "))
    edges[x-1].append(y-1)

stack = [0]
while stack:
    
    curr = stack[0]
    stack = stack[1:]

    for child in edges[curr]:

        allmul[child] = gcd(allmul[curr],a[child])
    
        dp[child][0] = allmul[curr]
        dp[child][1] = max(gcd(a[child],dp[curr][0]), gcd(a[child],dp[curr][1]))

for i in dp:

    print(max(i[0], i[1]), end=' ')

print()


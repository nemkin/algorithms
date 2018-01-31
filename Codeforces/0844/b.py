n, m = map(int, input().split(" "))

table = []

for i in range(n):

    table.append(list(map(int, input().split(" "))))

print(table)

dp = [[[1 for k in range(2)] for j in range(m+1)] for i in range(n+1)]

for i in range(n):
    
    for j in range(m):
   
        for k in range(2):
 
            if(dp[i-1][j-1][k] == dp[i-1][j][k] and dp[i-1][j-1][k] == dp[i][j-1][k]):

                dp[i][j][k] = 1

            else:

                dp[i][j][k] = dp[i-1][j][k] * (dp[i][j-1][k] - dp[i-1][j-1][k])
   

            dp[i][j][table[i][j]] *= 2

print(dp)


mod = 998244353
N = 100000

dp = [None, None]
dp[0] = [0] * (N+1)
dp[1] = [0] * (N+1)

dp[0][0] = 1
dp[1][0] = 1
dp[1][1] = 1

print(0)
print(0)

for i in range(2, N+1):
  dp[i%2][0] = 1
  dp[i%2][i] = 1
  for j in range(1, i):
    dp[i%2][j] = (dp[(i+1)%2][j-1] + dp[(i+1)%2][j]) % mod
  
  print(dp[i%2][i//2])

# T_T

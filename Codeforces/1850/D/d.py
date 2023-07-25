t = int(input())

while t:
  t-=1
  n, k = map(int, input().split())
  p = sorted(list(map(int, input().split())))
  dp = [0] * len(p)
  dp[0] = 1
  for i in range(1, len(p)):
    if k < p[i]-p[i-1]:
      dp[i] = 1
    else:
      dp[i] = dp[i-1] + 1
  print(n-max(dp))

import sys

n, t = map(int, input().split())
a = list(map(int, input().split()))

a = a*len(a)

dp = [0]*len(a)

dp[0] = 1

for i in range(1,len(a)):
    dp[i]

n = int(input())
dp = [[0]*n for i in range(n)]
s = list(map(int, input().split()))

def is_min(res, o):

    if res == -1:
        return o

    return min(res,o)

def is_dp(f, t):

    if t < f:
        return 0
    if f == t:
        return 1
    if f+1 == t:
        if s[f] == s[t]:
            return 1
        return 2

    if dp[f][t] != 0:
        return dp[f][t] 

    if s[f] == s[t]:
        dp[f][t] = is_dp(f+1, t-1)
        return dp[f][t]
    
    res = -1
    for i in range(f,t):

         res1 = is_dp(f,i)
         if res != -1 and res <= res1: 
            continue
         res = is_min(res, res1 + is_dp(i+1,t))

    dp[f][t] = res
    return dp[f][t]
 
print(is_dp(0,n-1))


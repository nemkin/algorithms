n = int(input())
a = list(map(int, input().split()))

mod = 998244353

def inv(n):
  return pow(n, mod-2, mod)

def nck(n,r):
  if n < r:
    return 0
  if r == 0:
    return 1
  fac = [0]*(n+1)
  fac[0] = 1
  for i in range(1,n+1):
    fac[i] = (fac[i - 1] * i) % mod
  return ((fac[n] * inv(fac[r]) % mod) * inv(fac[n - r]) % mod)

result = 1
for i in range(0, n, 3):
  x = sorted(a[i:i+3])
  if x[0] == x[1] and x[1] == x[2]:
    result *= 3
  elif x[0] == x[1]:
    result *= 2
  result = result % mod

result *= nck(n//3, n//6)
result = result % mod

print(result)
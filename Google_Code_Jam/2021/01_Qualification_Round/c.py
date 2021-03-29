z = int(input())
for z_i in range(z):
  n, c = map(int, input().split(' '))
  if c < n-1: 
    print(f"Case #{z_i+1}: IMPOSSIBLE")
    continue
  if n*(n+1)/2-1 < c:
    print(f"Case #{z_i+1}: IMPOSSIBLE")
    continue
  if n == 1:
    print(f"Case #{z_i+1}: 1")
    continue
  c -= (n-1)
  torev = list(range(n))
  for i in range(n-1):
    j = min(n-1-i, c)
    torev[i] = i + j
    c -= j
  l = list(range(1,n+1))
  for i in range(n-2,-1,-1):
    j = torev[i]
    l[i:j+1] = reversed(l[i:j+1])
  st = " ".join(map(str, l))
  print(f"Case #{z_i+1}: {st}")


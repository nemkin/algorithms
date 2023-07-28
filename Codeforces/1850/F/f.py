t = int(input())

while t:
  t-=1

  n = int(input())
  a = list(map(int, input().split()))

  cnt = [0]*(n+1)

  for ai in a:
    if ai <= n:
      cnt[ai]+=1

  frogs = [0]*(n+1)

  for i in range(1,n+1):
    for j in range(1,n//i+1):
      frogs[j*i] += cnt[i]

  print(max(frogs))

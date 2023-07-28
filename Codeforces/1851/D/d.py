t = int(input())

while t:
  t -= 1

  n = int(input())
  a = [0] + list(map(int, input().split()))

  done = [False] * (n+1)
  done[0] = True
 

  extra = -1
  ok = True

  for i in range(1, n):
    diff = a[i] - a[i-1]
    if 1<= diff and diff <= n and not done[diff]:
      done[diff] = True
    elif extra == -1:
      extra = diff
    else:
      ok = False
      break
  
  if ok:
    counted = 0
    sum = 0
    for i in range(n+1):
      if not done[i]:
        sum += i
        counted += 1
    
    if extra == -1:
      if counted != 1:
        ok = False
    else:
      if counted != 2 or sum != extra:
        ok = False

  if ok:
    print("YES")
  else:
    print("NO")

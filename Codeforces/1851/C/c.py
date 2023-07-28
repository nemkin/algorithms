t = int(input())

while t:
  t -= 1

  n, k = map(int, input().split())
  c = list(map(int, input().split()))

  count = 0
  color = c[0]
  switched = False
  for i in range(n):
    if count == k:
      if not switched:
        if c[0] == c[-1]:
          switched = True
          break
        count = 0
        color = c[-1]
        switched = True
      else:
        break
    if count < k:
      if c[i] == color:
        count += 1
    
  if k <= count and (switched or c[0] == c[-1]):
    print("YES")
  else:
    print("NO")

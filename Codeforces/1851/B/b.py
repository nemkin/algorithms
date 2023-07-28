t = int(input())

while t:
  t -= 1

  n = int(input())
  a = list(map(int, input().split()))

  a_sorted = sorted(a)

  ok = True
  for i in range(n):
    if (a[i]%2) != (a_sorted[i]%2):
      ok = False
      break
  
  if ok:
    print("YES")
  else:
    print("NO")

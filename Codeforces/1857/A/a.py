t = int(input())

while t:
  t -= 1

  n = int(input())
  a = list(map(int, input().split()))

  count_odd = 0
  for ai in a:
    if ai % 2:
      count_odd += 1
  
  if count_odd%2 == 0:
    print("YES")
  else:
    print("NO")
  
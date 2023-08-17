t = int(input())

while t:
  t -= 1

  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))

  c = []
  for i in range(n):
    c.append(a[i]-b[i])

  strength = max(c)
  print(c.count(strength))
  for i in range(n):
    if c[i] == strength:
      print(i+1, end=' ')
  print()

t = int(input())

while t:
  t-=1
  b,c,h = map(int, input().split())
  l = min(b-1, c+h)*2 + 1
  print(l)

t = int(input())

while t:
  t-=1
  r = ''.join([input() for _ in range(8)]).replace('.', '')
  print(r)

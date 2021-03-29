n = int(input())
for n_i in range(n):
  x, y, m = input().split()
  x = int(x)
  y = int(y)
  m = m.replace('?', '')
  xc = m.count('CJ')
  yc = m.count('JC')
  print(f"Case #{n_i+1}: {x*xc + y*yc}")


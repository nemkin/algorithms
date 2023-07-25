t = int(input())

while t:
  t-=1
  w = int(input())
  maxi = -1
  maxb = 0
  for i in range(1, w+1):
    a, b = map(int, input().split())
    if a <= 10 and maxb < b:
      maxi = i
      maxb = b

  print(maxi)

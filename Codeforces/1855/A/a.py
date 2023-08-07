t = int(input())

while t:
  t -= 1

  n = int(input())
  p = list(map(int, input().split()))

  cnt = 0
  for i in range(n):
    if (i+1) == p[i]:
      cnt += 1

  print(cnt // 2 + (cnt % 2))

t = int(input())

while t:
  t -= 1

  n = int(input())
  a = list(sorted(map(int, input().split())))

  current = 0
  for i in range(1,n-1):
    print(a[current], end=' ')
    current += n-i

  print(a[current], end=' ')
  print(a[current])

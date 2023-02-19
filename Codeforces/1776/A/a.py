tests = int(input())

for case in range(tests):
  n = int(input())
  a = list(map(int, input().split()))

  a.insert(0, 0)
  a.append(1440)

  walks = 0
  for i in range(1, n+2):
    diff = a[i] - a[i-1]
    walks += diff // 120

  if walks > 1:
    print("YES")
  else:
    print("NO")

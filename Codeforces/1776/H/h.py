tests = int(input())

for cases in range(tests):
  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))

  ai = n-1
  bi = n-1
  count = 0
  while 0 <= ai:
    if a[ai] == b[bi]:
      ai -= 1
      bi -= 1
    else:
      ai -= 1
      count += 1
  print(count)

t = int(input())

while t:
  t-=1

  n, k = map(int, input().split())
  a = list(map(int, input().split()))

  b = sorted([(a[i] % k if a[i] % k != 0 else k, n-i) for i in range(n)], reverse=True)

  print(" ".join(map(str, [n-b[i][1]+1 for i in range(n)])))


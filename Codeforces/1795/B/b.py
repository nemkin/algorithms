tests = int(input())

for case in range(tests):
  n, k = map(int, input().split())
  maxx, miny = 0, 51
  for i in range(n):
    x, y = map(int, input().split())
    if x <= k and k <= y:
      maxx = max(maxx, x)
      miny = min(miny, y)
  if maxx == miny and maxx == k:
    print("YES")
  else:
    print("NO")
  #print(maxx, miny)
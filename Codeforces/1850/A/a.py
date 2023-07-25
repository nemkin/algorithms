t = int(input())

while t:
  t-=1
  a, b, c = map(int, input().split())

  if (10 <= a+b) or (10 <= a+c) or (10 <= b+c):
    print("YES")
  else:
    print("NO")

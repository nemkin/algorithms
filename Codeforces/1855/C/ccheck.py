n = int(input())
a = list(map(int, input().split()))

q = int(input())
for i in range(q):
  x, y = map(int, input().split())
  a[x-1] = a[x-1] + a[y-1]

print(a)

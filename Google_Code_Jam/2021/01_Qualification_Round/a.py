n = int(input())
for n_i in range(n):
  cost = 0
  m = int(input())
  l = list(map(int, input().split(' ')))
  for i in range(m-1):
    j = l.index(min(l[i:m]))
    cost += j-i+1
    l[i:j+1] = reversed(l[i:j+1])
  print(f"Case #{n_i+1}: {cost}")


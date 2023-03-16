n, m, mod = map(int, input().split())

adjlist = [[] for _ in range(n)]
found = [False] * n
si = [0]*n # Size of components, at most n components.

for i in range(m):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  adjlist[a].append(b)
  adjlist[b].append(a)

comps = 0
for v in range(n):
  if not found[v]:
    stack = [v]
    while stack:
      u = stack.pop()
      if not found[u]:
        found[u] = True
        si[comps] += 1
        for w in adjlist[u]:
          if not found[w]:
            stack.append(w)
    comps += 1

if mod == 1:
  print(0) # .........
elif comps == 1:
  print(1)
else:
  ans = pow(n, comps-2, mod)
  for i in range(comps):
    ans *= si[i]
    ans %= mod

  print(ans)
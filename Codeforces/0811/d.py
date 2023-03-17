import sys

n, m = map(int, input().split())
field = [input() for _ in range(n)]

found = False
for tx in range(n):
  for ty in range(m):
    if field[tx][ty] == 'F':
      found = True
      break
  if found:
    break

def step(move):
  print(move)
  sys.stdout.flush()
  x, y = map(int, input().split())
  x, y = x-1, y-1
  if x==tx and y == ty:
    sys.exit()
  return x, y

u = 'U'
d = 'D'
l = 'L'
r = 'R'

if field[0][1] != '*':
  x, y = step(r)
  if y == 0:
    l, r = r, l
  else:
    x, y = step(l)
  while x+1 < n and field[x+1][y] == '*':
    if y+1 < m and field[x][y+1] == '*':
      break
    x, y = step(r)
  if y+1<m and field[x][y+1] != '*':
    x, y = step(d)
    if x == 0:
      u, d = d, u
elif field[1][0] != '*':
  x, y = step(d)
  if x == 0:
    u, d = d, u
  else:
    x, y = step(u)
  while y+1 < m and field[x][y+1] == '*':
    if x+1 < n and field[x+1][y] == '*':
      break
    x, y = step(d)
  if x+1 < n and field[x+1][y] != '*':
    x, y = step(r)
    if y == 0:
      l, r = r, l

visited = [[False for _ in range(m)] for _ in range(n)]
moves = []

def dfs(x, y):
  visited[x][y] = True
  if x == tx and y == ty:
    return True
  for mx, my, move in [[-1, 0, u], [1, 0, d], [0, -1, l], [0, 1, r]]:
    if x+mx < 0 or n <= x+mx or y+my < 0 or m <= y+my:
      continue
    if not visited[x+mx][y+my] and field[x+mx][y+my] != '*':
      if dfs(x+mx, y+my):
        moves.append(move)
        return True
  return False

dfs(x, y)
for m in reversed(moves):
  step(m)

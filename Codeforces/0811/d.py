import sys

n, m = map(int, input().split())
field = [input() for _ in range(n)]
x, y = 0, 0
u, d, l, r = 'U', 'D', 'L', 'R'

def direction(mx, my):
  if mx == -1:
    return u
  if mx == 1:
    return d
  if my == -1:
    return l
  if my == 1:
    return r

def step(mx, my):
  global x, y, u, d, l, r
  prevx, prevy = x, y
  print(direction(mx, my))
  sys.stdout.flush()
  x, y = map(int, input().split())
  x, y = x-1, y-1
  if prevx == x and prevy == y:
    if mx:
      u, d = d, u
    if my:
      l, r = r, l
    return step(mx, my)
  return x, y

stack = [[x,y]]
visited = [[False for _ in range(m)] for _ in range(n)]
move = [[['X', 'X'] for _ in range(m)] for _ in range(n)]

while stack:
  cx, cy = stack.pop()
  print('E  ', cx, cy)
  if field[cx][cy] == 'F':
    fx, fy = cx, cy
    break
  if visited[cx][cy]:
    continue
  visited[cx][cy] = True
  for mx, my in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
    print("M ", mx, my)
    if cx+mx < 0 or n <= cx+mx or cy+my < 0 or m <= cy+my:
      continue
    if field[cx+mx][cy+my] == '*':
      continue
    print("OK")
    stack.append([cx+mx, cy+my])
    print(stack)
    move[cx+mx][cy+my] = [mx,my]

movelist = []
while not (cx == x and cy == y):
  mx, my = move[cx][cy]
  movelist.append([mx, my])
  cx -= mx
  cy -= my

for mx, my in reversed(movelist):
  step(mx, my)

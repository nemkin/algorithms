n = int(input())
a = list(map(int, input().split()))

b = []
volt2es = False
for i in range(n):
  if a[i] == 2:
    if volt2es:
      pass
    else:
      volt2es = True
      b.append(a[i])
  if a[i] == 1:
    if volt2es:
      pass
    else:
      b.append(a[i])
  if a[i] == 0:
    if volt2es:
      volt2es = False
    else:
      b.append(a[i])

n = len(b)
c = []
volt2es = False
for i in range(n-1, -1, -1):
  if b[i] == 2:
    if volt2es:
      pass
    else:
      volt2es = True
      c.append(b[i])
  if b[i] == 1:
    if volt2es:
      pass
    else:
      c.append(b[i])
  if b[i] == 0:
    if volt2es:
      volt2es = False
    else:
      c.append(b[i])

x = c.count(2) + c.count(0)

c = [2] + list(reversed(c)) + [2]
n = len(c)

kell0 = False
volt0 = False
for i in range(n):
  if c[i] == 1:
    if not volt0:
      kell0 = True
  if c[i] == 0:
    if kell0:
      kell0 = False
      volt0 = False
    else:
      volt0 = True
      kell0 = False
  if c[i] == 2:
    if kell0:
      x+=1
    kell0 = False
    volt0 = False

print(x)

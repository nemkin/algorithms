import sys
from collections import Counter

input = sys.stdin.readline

def main():
  
  t = int(input())

  while t:
    t -= 1

    n = int(input())

    x = [0]*n
    y = [0]*n
    for i in range(n):
      x[i], y[i] = map(int, input().split())

    d1 = [x[i] + y[i] for i in range(n)]
    d2 = [x[i] - y[i] for i in range(n)]

    x = sorted(x)
    y = sorted(y)
    d1 = sorted(d1)
    d2 = sorted(d2)

    res = 0
    cnt = 0
    for i in range(1,n):
      if x[i] == x[i-1]:
        cnt+=1
      else:
        res += cnt*(cnt+1)
        cnt = 0
    res += cnt*(cnt+1)
    
    cnt = 0
    for i in range(1,n):
      if y[i] == y[i-1]:
        cnt+=1
      else:
        res += cnt*(cnt+1)
        cnt = 0
    res += cnt*(cnt+1)
    
    cnt = 0
    for i in range(1,n):
      if d1[i] == d1[i-1]:
        cnt+=1
      else:
        res += cnt*(cnt+1)
        cnt = 0
    res += cnt*(cnt+1)

    cnt = 0
    for i in range(1,n):
      if d2[i] == d2[i-1]:
        cnt+=1
      else:
        res += cnt*(cnt+1)
        cnt = 0
    res += cnt*(cnt+1)

    print(res)

main()
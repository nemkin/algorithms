def works(n, c, s, w):
  need = sum(map(lambda si: (si+2*w) * (si+2*w), s))
  return need <= c

def main():
  t = int(input())

  while t:
    t-=1
    n, c = map(int, input().split())
    s = list(map(int, input().split()))

    l = 0
    r = 1 << 64

    while l < r:
      mid = (l+r) // 2 + (l+r) % 2
      if works(n, c, s, mid):
        l = mid
      else:
        r = mid - 1
    print(l)

main()

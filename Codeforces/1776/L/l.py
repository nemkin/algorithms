n = int(input())

s = input()
p = s.count('+')
m = n-p

pmdiff = abs(p-m)
pmmin = min(p, m)

tests = int(input())

for case in range(tests):
  a, b = map(int, input().split())
  
  kompenzalando = pmdiff * min(a,b)

  kompenzalo = abs(a-b)
  ennyiszer = pmmin

  if kompenzalo == 0:
    if pmdiff == 0:
      print("YES")
    else:
      print("NO")
    continue

  if kompenzalando % kompenzalo == 0 and kompenzalando / kompenzalo <= ennyiszer:
    print("YES")
  else:
    print("NO")

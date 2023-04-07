cases = int(input())

for case in range(cases):
  n = int(input())
  a = list(map(int, input().split()))

  count0 = 0
  for i in range(n):
    if a[i] == 0:
      count0 += 1

  count0_in_first = 0
  for i in range(count0):
    if a[i] == 0:
      count0_in_first += 1

  p = count0 * (n-count0)

  negyzetszamokosszege = 0
  for i in range(1, count0_in_first+1):
    negyzetszamokosszege += i * i
  
  for i in range(1, count0_in_first+1):
    p *= negyzetszamokosszege 

  q = fact[count0 - count0_in_first]
  print(p, q)
  mod = 998244353

  def gcd(a, b):
    x = 1
    y = 0
    
    x1 = 0
    y1 = 1
    a1 = a
    b1 = b
    while (b1):
      q = a1 / b1;
      x, x1 = x1, x - q * x1
      y, y1 = y1, y - q * y1
      a1, b1 = b1, a1 - q * b1
    return a1, x, y


  print(gcd(q, mod))

  # Ha count0_in_first = count0, akkor kész vagyunk, 0.
  # Ha count0_in_first = count0 - 1, akkor pont 1 elemet kell cserélni.
  #
  # Ha nem a jó indexpárt választja ki, akkor kvázi noop, de ha a jót
  # akkor vége. Geometriai eloszlás.
  # p = 1 / (n choose 2)
  #
  # 1/p = (n choose 2)
  # 
  # Ha count0_in_first = count0 - 2, akkor van 2 - 2 elem a két oldalon amit
  # ha megtalál akkor 1-el csökken az elemek száma és vissza az előző esethez.
  # Várható érték lineáris, akkor is ha összefüggő eseményekről van szó.
  # p = (n choose 2) * (1/count0_in_first^2 + ... + 1)
  # majd az előző cucu hozzáadva.
  # E = (1/2 + 1) * count0 * (n-count0)     2*2 / (n choose 2)
  # stb
  # E = (1/(count0-count0_in_first) + ... + 1) *   3*3 / (n choose 2)
  # summa cucc felül és faktoriális alul

  # p = count0 * (n-count0) * (summa ahol a faktoriálisból mindig egy elem marad ki)
  # q = faktoriális


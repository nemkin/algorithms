t = int(input())

while t:
  t -= 1

  n = int(input())
  a = list(map(int, input().split()))

  a_indexed = []
  for i in range(n):
    a_indexed.append((a[i], i))
  
  a_indexed = sorted(a_indexed)
  #print(a_indexed)

  sol = [0]*n

  power_before = 0
  power_after = 0
  for i in range(1, n):
    power_after += abs(a_indexed[0][0]-a_indexed[i][0])+1

  sol[a_indexed[0][1]] = power_before+1+power_after
  #print(power_before, 1, power_after, power_before+1+power_after)
  #print(power_before + 1 + power_after, end=' ')

  for j in range(1, n):
    power_before += (j-1)*(a_indexed[j][0]-a_indexed[j-1][0])
    power_before += a_indexed[j][0]-a_indexed[j-1][0]+1

    power_after -= (n-j-1)*(a_indexed[j][0]-a_indexed[j-1][0])
    power_after -= a_indexed[j][0]-a_indexed[j-1][0]+1

    
    sol[a_indexed[j][1]] = power_before+1+power_after
    #print(power_before, 1, power_after, power_before+1+power_after)
    #print(power_before + 1 + power_after, end=' ')

  print(" ".join(map(str, sol)))


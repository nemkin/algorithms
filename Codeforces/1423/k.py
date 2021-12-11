import sys
import math as np

def x(N):
  primes = [N*N+1]*(N+1)
  cp = 0
  smallest_divisor = (N+1)*[0] #[0 for i in range(0,N+1)] # Prime or self
 
  for i in range(2,N+1):
    if smallest_divisor[i] == 0: # If prime
      smallest_divisor[i] = i
      primes[cp] = i
      cp += 1
 
    for j in primes:
      if j > smallest_divisor[i]:
        break
      n = i*j
      if n > N:
        break
      #assert smallest_divisor[n] == 0
      smallest_divisor[n] = j
 
  return primes
 
def main():
    n = int(input())
    t = list(map(int, input().split(' ')))
    m = max(t)

    primes = set(x(m))

    pref = [0]*(m+1)

    for i in range(2,m+1):
        pref[i] = pref[i-1]
        if i in primes:
            pref[i] += 1

    res = []

    for case in t:
        first = max(2,int(np.ceil(np.sqrt(case+1))))
        s = pref[case] - pref[first-1]
        res.append(str(s+1))

    sys.stdout.write('\n'.join(res))

main()

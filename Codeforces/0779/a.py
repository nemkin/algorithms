import sys
from collections import Counter

n = int(input())
a = Counter(map(int, input().split()))
b = Counter(map(int, input().split()))

counta = 0
countb = 0

for i in range(1,5+1):
    diff = abs(a[i] - b[i])
    if diff%2:
        print(-1)
        sys.exit(0)
    
    if a[i] < b[i]:
        countb += int(diff/2)
    if b[i] < a[i]:
        counta += int(diff/2)

if counta != countb:
    print(-1)
    sys.exit(0)

print(counta)

   

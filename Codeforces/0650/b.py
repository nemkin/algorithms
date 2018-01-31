n,a,b,T = map(int, input().split())
p = input()

right = [0]*n
left = [0]*n

for i,o in enumerate(p):
   right[i] = a+b+1 if o='w' else a+1

for i,o in enumerate(reversed(p)):
   left[i] = a+b+1 if o='w' else a+1






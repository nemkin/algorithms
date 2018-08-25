n = int(input())
a = list(map(int, input().split()))

longest = 0
maxlongest = 0

for i in range(0,n-1):
   if a[i+1] <= 2*a[i]:
        longest +=1
   else:
        maxlongest = max(maxlongest, longest)
        longest = 0

maxlongest = max(maxlongest, longest)

print(maxlongest+1) 
    

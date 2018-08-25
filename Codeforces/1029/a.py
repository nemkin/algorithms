n, k = map(int, input().split())
t = input()

for i in range(1,len(t)+1):

    if len(t) % i != 0:
        continue

    substr = t[:i]
    times = int(len(t) / i)
    
    ist = substr*times 
    if ist == t:
        break 
if 1<len(ist):
    for i in range(len(ist)-1,0,-1):
        if ist[len(ist)-i : len(ist)] == ist[0 : i]:
            ist = ist[0:len(ist)-i]
            break
         
        
print(ist*(k-1) + t)

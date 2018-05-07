n = int(input())
a = list(map(int, input().split()))


count = 1
mc = 1

for i in range(1,len(a)):

    if a[i-1] <= a[i]:
       count += 1 
    else:
        count = 1

    if mc < count:
        mc = count

print(mc)
        

    

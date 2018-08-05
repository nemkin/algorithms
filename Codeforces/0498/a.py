hx, hy = map(int, input().split())
ux, uy = map(int, input().split())
n = int(input())

count = 0

for i in range(n):
    a,b,c = map(int, input().split())
    
    h = a*hx + b*hy + c
    u = a*ux + b*uy + c

    if h*u<0:
        count += 1

print(count)
        

R,C,F,N,B,T = list(map(int, input().split()))

rides = []

for i in range(N):
    a,b,x,y,s,f = list(map(int, input().split()))

    l = abs(a-x)+abs(b-y)
    rides.append([a,b,x,y,s,f, l,i])

rides = sorted(rides, key=lambda x: -x[6])

count = len(rides)

first = count//10

print(first)
print(R,C,F,N-first,B,T)

for i in rides[first:]:
    print(" ".join(map(str, i[:6])))

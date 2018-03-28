n = int(input())
parent = list(map(int, input().split()))
c = list(map(int, input().split()))

cnt = 1
for i in range(1,n):
    if c[i] != c[parent[i-1]-1]:
        cnt+=1

print(cnt)

n,m,k = map(int, input().split())
a = list(map(int, input().split()))
e = sorted(a)

best = e[-1]
second = e[-2]

happy = (best * k + second) * (m // (k+1)) + best * (m % (k+1))

print(happy)


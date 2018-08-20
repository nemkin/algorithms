x = [500, 1000, 1500, 2000, 2500]
m = list(map(int, input().split()))
w = list(map(int, input().split()))
hs, hu = map(int, input().split())

s = 0
for i in range(len(x)):
    s += int(max(0.3*x[i], (250-m[i])*x[i]/250 - 50*w[i]))

s += hs*100
s -= hu*50

print(s)

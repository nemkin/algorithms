n = int(input())
t = list(map(int, input().split()))

zeros = 0
ones = sum(t)

m = zeros + ones

for b in range(n):

    if t[b] == 0:
        zeros += 1
    else:
        ones -= 1

    if m < zeros + ones:
        m = zeros + ones

print(m)

cards = int(input())

result = 0
n = 0
while True:
    n+=1
    needed = 2*n + 3*n*(n-1)/2

    if cards < needed:
        break
    if (cards - needed)%3 == 0:
        result+=1

print(result)

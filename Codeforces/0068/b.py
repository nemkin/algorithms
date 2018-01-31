n, k = map(int, input().split())
a = list(map(int, input().split()))

result = sum(a)/n
eps = 0.0000000001

while True: 

    transferred = (100-k)/100 * sum(map(lambda x: x-result if x-result>0 else 0, a))
    missing = sum(map(lambda x: result-x if result-x>0 else 0, a))

    if abs(transferred - missing) < eps:
        print(result)
        break


    result = result + (transferred-missing)/n

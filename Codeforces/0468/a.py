import sys

n = int(input())

if 6<=n:
    print("YES")

    print("6 * 4 = 24")
    print("3 - 2 = 1")
    print("1 - 1 = 0")
    print("0 * 5 = 0")

    for i in range(7,n+1):
        print("0 * "+str(i)+" = 0")

    print("0 + 24 = 24")
    
    sys.exit(0)

if 5 == n:

    print("YES")

    print("5 + 1 = 6")
    print("6 * 4 = 24")
    print("3 - 2 = 1")
    print("24 * 1 = 24")

    sys.exit(0)

if 4 == n:

    print("YES")

    print("1 + 2 = 3")
    print("3 + 3 = 6")
    print("6 * 4 = 24")

    sys.exit(0)

print("NO")

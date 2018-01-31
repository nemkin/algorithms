s = input()
k = int(input())

if len(s) < k:
    print("impossible")
else:
    print(max(0,k-len(set(s))))

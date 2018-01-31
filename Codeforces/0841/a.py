n, k = map(int, input().split(" "))
s = input()

print("YES") if max(s.count(letter) for letter in set(s)) <= k else print("NO")

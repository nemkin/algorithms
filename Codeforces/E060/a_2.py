n = int(input())
a = list(map(int, input().split()))
max_a = max(a)
counter = 0
max_counter = 0
for a_i in a:
  if a_i == max_a:
    counter += 1
  else:
    counter = 0
  if max_counter < counter:
    max_counter = counter
print(max_counter)


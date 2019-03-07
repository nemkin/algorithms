n = int(input())
a = list(map(int, input().split()))

print()

length = 1
value = a[0]

max_length = 1
max_value = a[0]

for a_i in a[1:]:

  if (a_i * (length + 1)) <= (value + a_i):
    value += a_i
    length += 1 
  else:
    value = a_i
    length = 1

  print(value, length)

  left = max_value * length
  right = value * max_length
  if left < right or (left == right and max_length < length):
    max_value = value
    max_length = length
    
print()
print(max_value, max_length)

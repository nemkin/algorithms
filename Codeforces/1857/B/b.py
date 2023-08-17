t = int(input())

while t:
  t -= 1

  aorig = input()
  a = list(reversed(aorig))

  plus = 0
  where = -1
  for i in range(len(a)):
    digit = int(a[i])

    if plus:
      where = i
      digit += 1

    
    if 5 <= digit:
      plus = 1
      digit = 0
    else:
      plus = 0

  if plus:
    print('1' + ''.join(['0'] * len(a)))
  elif where == -1:
    print(aorig)
  else:
    print(str(int(aorig[:-where])+1) + ''.join(['0']*where))


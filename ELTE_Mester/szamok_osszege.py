# https://github.com/lezsakdomi/elte-mester-data/blob/master/Sz%C3%A1melm%C3%A9leti%20algoritmusok/Sz%C3%A1mok%20%C3%B6sszege/feladat.pdf

import sys

n, x = map(int, input().split(" "))
s = list(map(int, input().split(" ")))


for i_1 in range(n):
  x_rem = x - s[i_1]

  i_2 = i_1 + 1
  i_3 = n-1

  while True:
    if i_2 >= i_3: # Ha átlépték egymást a pointerek akkor nincs találat
      break
    sum = s[i_2] + s[i_3]
    if sum == x_rem: # Találat
      print(s[i_1], s[i_2], s[i_3])
      sys.exit() # Kiírjuk, megállunk
    if sum < x_rem: # Ha túl kevés az összeg bal pointert növeljük
       i_2 += 1
    elif sum > x_rem: # Ha túl sok az összeg jobb pointert csökkentjük
       i_3 -= 1

print(-1)

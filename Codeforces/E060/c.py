x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
n = int(input())
s = input()

if x1 == x2:

  good_h = 'N'
  bad_h = 'O'
  good_h_count = 0
  bad_h_count = s.count('R') + s.count('L')

else:
  if x1 < x2:
    good_h = 'R'
    bad_h = 'L'
  else:
    good_h = 'L'
    bad_h = 'R'
  
  good_h_count = s.count(good_h)
  bad_h_count = s.count(bad_h)

if y1 == y2:

  good_v = 'N'
  bad_v = 'O'
  good_v_count = 0
  bad_v_count = s.count('U') + s.count('D')

else:

  if y1 < y2:
    good_v = 'U'
    bad_v = 'D'
  else:
    good_v = 'D' 
    bad_v = 'U'
  
  good_v_count = s.count(good_v)
  bad_v_count = s.count(bad_v)
  
  good_count = good_h_count + good_v_count 
  bad_count = bad_h_count + bad_v_count


dist = abs(x1-x2) + abs(y1-y2)
steps = dist//2 + dist%2

if good_count == 0:

  if dist == 0:
    print(0)
  else:
    print(-1)

else:

  full_rotations = steps // good_count
  remainder = steps % good_count
  
  count = 0
  i = -1
  
  if remainder != 0:
    for i, s_i in enumerate(s):
    
      if s_i == good_h or s_i == good_v:
        count += 1
    
      if count == remainder:
        break
  
  print(full_rotations * n + i + 1) 

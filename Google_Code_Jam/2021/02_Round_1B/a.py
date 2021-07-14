import itertools

nsecs_in_sec = pow(10,9)

def correct_order(hticks, mticks, sticks):

  st = sticks - sticks % (720 * nsecs_in_sec)
  mt = mticks - sticks // 60
  ht = hticks - mticks // 12

  n = sticks - st
  s = st / nsecs_in_sec / 720
  m = mt / nsecs_in_sec / 60 / 12
  h = ht / nsecs_in_sec / 60 / 60 / 1

  if h.is_integer() and m.is_integer() and s.is_integer():
    return int(h),int(m),int(s),int(n)
  else:
    return None,None,None,None

def any_order(a,b,c):
  for x,y,z in itertools.permutations([a,b,c]):
    h,t,m,s = correct_order(x,y,z)
    if h is not None:
      return h,t,m,s
  print("CASE____")
  for x,y,z in itertools.permutations([a,b,c]):
    #print("CASE ORDER")
    diff = z % (720 * nsecs_in_sec)
    x -= diff
    y -= diff
    z -= diff
    for i in range(360*12*10):
      add = i * nsecs_in_sec
      x = (x + add) % (360*12*10*nsecs_in_sec)
      y = (y + add) % (360*12*10*nsecs_in_sec)
      z = (z + add) % (360*12*10*nsecs_in_sec)
      #print(x,y,z)
      h,t,m,s = correct_order(x,y,z)
    if h is not None:
      return h,t,m,s
  return None,None,None,None

cases = int(input())
for case_i in range(cases):
  a,b,c = map(int, input().split(' '))
  h,m,s,n = any_order(a,b,c)
  if h is not None:
    print(f"Case #{case_i+1}: {h} {m} {s} {n}")
    continue

import re

tests = int(input())

def occ(text, sub):
    return len(re.findall('(?={0})'.format(re.escape(sub)), text))

for case in range(tests):
  input()
  a = input()
  b = input()
  c = a + b[::-1]
  #print(c)
  rc = occ(c, "RR")
  rb = occ(c, "BB")
  #print(rc + rb)
  if rc + rb < 2:
    print("YES")
  else:
    print("NO")
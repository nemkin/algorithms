n, k = map(int, input().split(' '))
s = list(map(int, input().split(' ')))

def fits(t):
  curr = 0
  count = 1
  indexes = []
  for s_i in s:
    if curr + s_i <= t: # Belefér a mostaniba
      curr += s_i
      indexes.append(count)
    else:  # Nem fér bele a mostaniba, újat nyitunk
      count += 1
      indexes.append(count)
      curr = s_i
    if count > k:
      return None
  return indexes

min_t = max(s)
max_t = sum(s)

while min_t < max_t:
  mid_t = (max_t + min_t) // 2
  res = fits(mid_t)
  if res is None:
    min_t = mid_t+1
  else:
    max_t = mid_t

mid_t = (max_t + min_t) // 2
res = fits(mid_t)

print(mid_t)
print(" ".join(map(lambda i: str(res.index(i+1)+1), range(k))))

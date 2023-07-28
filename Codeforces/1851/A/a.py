t = int(input())

while t:
  t -=1

  n_people, m_steps, k_diff, vlads_height = map(int, input().split())

  heights = list(map(int, input().split()))

  people = 0
  for height in heights:
    height_diff = abs(vlads_height - height)
    if height_diff % k_diff == 0:
      step_diff = height_diff / k_diff
      if 1 <= step_diff and step_diff <= m_steps-1:
        people += 1
  print(people)

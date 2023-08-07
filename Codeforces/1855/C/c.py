def main():
  t = int(input())

  while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))

    first_add = 0
    for i in range(1, n):
      if abs(a[i]) > abs(a[first_add]):
        first_add = i
    
    print(2*(n-1))

    for i in range(n):
      if i != first_add:
        print(i+1, first_add+1)
    
    if 0 < a[first_add]:
      for i in range(n-1):
        print(i+2, i+1)
    else:
      for i in range(n-2, -1, -1):
        print(i+1, i+2)

main()

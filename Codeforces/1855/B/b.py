def main():
  t = int(input())

  while t:
    t -= 1
    n = int(input())
    
    i = 2
    while True:
      if n%i:
        print(i-1)
        break
      i+=1

main()
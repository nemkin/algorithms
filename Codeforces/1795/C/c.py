tests = int(input())

for case in range(tests):

  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))

  teljes_ivasok_nyit = [0]*n
  teljes_ivasok_zar = [0]*n
  reszben_ivasok = [0]*n

  bpref = [0] * n
  bpref[0] = b[0]
  for i in range(1, n):
    bpref[i] = bpref[i-1] + b[i]
  
  for tea in range(n):
    first_taster = tea
    
    # Find last taster
    start = first_taster + 1
    end = n-1

    additional = 0 if first_taster == 0 else bpref[first_taster-1]
    query_last_taster = a[tea] + additional

    #print("Tea: ", a[tea])
    #print("Additional: ", additional)
    #print("Query: ", query_last_taster)
    if b[first_taster] >= a[tea]:
      reszben_ivasok[first_taster] += min(a[tea], b[first_taster])
      #print("Tea: ", tea, " Csak ő iszik", first_taster)
    elif bpref[end] <= query_last_taster:
      last_taster = end
      teljes_ivasok_nyit[first_taster] += 1
      teljes_ivasok_zar[last_taster] -= 1
      #print("Tea: ", tea, " Mindenki iszik", first_taster, last_taster)
    else:
      #print("Query: ", query_last_taster)
      #print("Bpref: ", bpref)
      while start < end:
        #print("Start: ", start)
        #print("End: ", end)
        mid = start + (end-start)//2 #+ (end-start)%2
        #print("Mid: ", mid)
        if bpref[mid] > query_last_taster:
          #print("Bigger!")
          end = mid
        else:
          #print("Smaller or equal!")
          start = mid + 1
      last_taster = start
      #print("Tea: ", tea, "From: ", first_taster, "To: ", last_taster-1, "Részben: ", last_taster, "Ennyit: ", min(b[last_taster], a[tea] - (bpref[last_taster-1]-additional)))
      teljes_ivasok_nyit[first_taster] += 1
      teljes_ivasok_zar[last_taster-1] -= 1
      reszben_ivasok[last_taster] += min(b[last_taster], a[tea] - (bpref[last_taster-1]-additional))

  teljes_ivasok_total = [0]*n
  hanyszor = 0
  for i in range(n):
    #print("Teljes ivások, i:", i)
    #print(teljes_ivasok_total)
    hanyszor += teljes_ivasok_nyit[i]
    teljes_ivasok_total[i] += hanyszor*b[i]
    hanyszor += teljes_ivasok_zar[i]
  #print("Teljes ivások")
  #print(teljes_ivasok_total)
  #print("Nyit:")
  #print(teljes_ivasok_nyit)
  #print("Zar:")
  #print(teljes_ivasok_zar)
  #print("Részben ivások")
  #print(reszben_ivasok)

  print(" ".join(map(str, [teljes_ivasok_total[i] + reszben_ivasok[i] for i in range(n)])))


  
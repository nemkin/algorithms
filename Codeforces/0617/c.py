n,x1,y1,x2,y2 = map(int, input().split(" "))

cords = []

for i in range(n):
    x,y = map(int, input().split(" "))
    cords.append({"x": x, "y": y, "d1": pow((x-x1),2) + pow((y-y1),2), "d2": pow((x-x2),2) + pow((y-y2),2)})

cords = sorted(cords, key=lambda d: d["d1"])

minval = max(cords, key=lambda d: d["d2"])["d2"]

if cords[n-1]["d1"] < minval:
    minval = cords[n-1]["d1"]

for i in range(n-1):

    val = cords[i]["d1"] + max(cords[i+1:], key=lambda d: d["d2"])["d2"]
    
    if val<minval:
        minval = val

print(minval)
    

r,g,b = map(int, input().split(" "))

result0 = r//3+g//3+b//3

if 1<=r and 1<=g and 1<=b:
    result1 = 1 + (r-1)//3+(g-1)//3+(b-1)//3
else:
    result1 = 0

if 2<=r and 2<=g and 2<=b:
    result2 = 2 + (r-2)//3+(g-2)//3+(b-2)//3
else:
    result2 = 0

result = max(result0,result1,result2)

print(result)


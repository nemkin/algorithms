# a*x + b*y = c linearis kongruencia pontosan akkor megoldhato
# ha (a,b) legnagyob kozos osztoja osztja c-t is.
import math
a, b, c = map(int, input().split())
print("Yes" if c % math.gcd(a,b) == 0 else "No")

# a=14, b=19, c= 144-re
# 13*a - 2*b = c a megoldás, ami miatt gcd osztója lesz c-nek, de
# negatívszor nem tudunk lőni Ivory-val. :(

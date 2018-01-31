import sys
import math

def modfact(n, p):
	f = 1
	for i in range(1, n+1):
		if i==p:
			continue
		f = (f*i) % p
	return f

def powmod(a, b, mod):
	if b==0:
		return 1
	if b==1:
		return a%mod
	x = powmod(a, b//2, mod)
	return (x*x*powmod(a, b%2, mod))  % mod
#print(modfact(4, 5), modfact(10, 71))
#print(powmod(3, 123456789123, 10))

n,p,r = map(int, input().split())

if n == 2:
	if r==1:
		print(2,1)
	else:
		print("-1 -1")
	sys.exit(0)
	
if n >= 2*p:
	if r == 0:
		print("2 1")
		sys.exit(0)
	else:
		print("-1 -1")
		sys.exit(0)
		
if n>= p:
	if r == 2:
		for k in range(2,n+1):
			if k!=p:
				print(str(k), str(1))
				sys.exit(0)
	else:
		nmod = modfact(n, p)
		
		c = (r*powmod(nmod, p-2, p)) % p
		
		if 1<=c:
			print(p,c)
			sys.exit(0)
		else:
			print(-1,-1)
			sys.exit(0)
		
		#for c in range(2, p):
		#		if ((c*nmod) % p) == r:
		#			print(str(p), str(c))
	#				sys.exit(0)
					
if n<p:
	if r == 0:
		print("-1 -1")
		sys.exit(0)
		
	else:
		nmod = modfact(n,p)
		#rights = (r*(nmod**(p-2))) % p
		rights = (r*powmod(nmod, p-2, p)) % p
		
		for k in range(2,n+1):
			v = (k*rights)%p
			if 1<=v and v<k:
				print(str(k), str(v))
				sys.exit(0)
	
print("-1 -1")

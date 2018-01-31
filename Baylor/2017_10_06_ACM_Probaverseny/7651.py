d,h = 0,0
st = set()

from operator import mul    # or mul=lambda x,y:x*y
from fractions import Fraction
import os, sys
from functools import reduce
import math

factor = [math.factorial(i) for i in range(33)]


def nCk(n,k): 
	return factor[n] // factor[k] // factor[n-k]
  #return int( reduce(mul, (Fraction(n-i, i+1) for i in range(k)), 1) )

def calc(l):
	#print(l)
	global d,h,st
	ret = 1
	summ = h
	for i in l:
		ret *= nCk(summ, i)
		summ -= i
	return ret

def bejar(l):
	global d,h
	if sum(l) > h:
		return
	#print(l)
	if len(l) == d:
		if sum(l) == h:
			#print(l)
			st.add(calc(l))
		return
	if sum(l) == h:
		while (len(l) < d):
			l.append(0)
		st.add(calc(l))
		#print(l)
	s = sum(l)
	mx = h if l==[] else l[-1]
	for i in range(1, mx+1):
		bejar(l+[i])
		

while True:
	try:
		d,h = list(map(int, input().split()))
		h-=1
	except EOFError:
#		print('Input end')
		break
	
	st = set()
	l = []
	bejar(l)
	
	ls = list(st)
	ls.sort()
	for i in ls:
		print(i)
	

import copy
t = int(input())
for case in range(1,t+1):
	n,r,o,y,g,b,v = [ int(_) for _ in input().split() ]
	
	if (r == g and o==0 and y == 0 and b == 0 and v == 0):
		result = "".join(i for j in zip('R'*r, 'G'*g) for i in j)
		print("Case #"+str(case)+": "+result)
		continue

	if (b == o and r==0 and y == 0 and g == 0 and v == 0):
		result = "".join(i for j in zip('B'*b, 'O'*o) for i in j)
		print("Case #"+str(case)+": "+result)
		continue

	if (y == v and r==0 and o == 0 and g == 0 and b == 0):
		result = "".join(i for j in zip('Y'*y, 'V'*v) for i in j)
		print("Case #"+str(case)+": "+result)
		continue

	if (r < g+1) or (b<o+1) or (y<v+1):
		print("Case #"+str(case)+": IMPOSSIBLE") 
		continue

	lettersleft = {'R' : r-g, 'B' : b-o, 'Y' : y-v}
	l1 = max(lettersleft, key=lettersleft.get)
	lettersleft.pop(l1)	
	l2 = max(lettersleft, key=lettersleft.get)
	lettersleft.pop(l2)
	l3 = max(lettersleft, key=lettersleft.get)
	lettersleft ={'R' : r-g, 'B' : b-o, 'Y' : y-v}
 
	if(lettersleft[l1] > lettersleft[l2]+lettersleft[l3]): 
		print("Case #"+str(case)+": IMPOSSIBLE")
		continue

	base = l1*lettersleft[l1]
	zagger = l2*lettersleft[l2] + l3*(lettersleft[l1]-lettersleft[l2])

	remainder = l3*(lettersleft[l3]+lettersleft[l2]-lettersleft[l1])
	
	result = "".join(i for j in zip(base, zagger) for i in j)

	remainder = remainder + "X"*(len(result)-len(remainder))
	
	result = "".join(i for j in zip(result, remainder) for i in j)
	result = result.replace("X","")

	rreplace = "".join(i for j in zip('R'*g,'G'*g) for i in j)+'R'
	breplace = "".join(i for j in zip('B'*o,'O'*o) for i in j)+'B'
	yreplace = "".join(i for j in zip('Y'*v,'V'*v) for i in j)+'Y'

	result = result.replace('R',rreplace,1)
	result = result.replace('B',breplace,1)
	result = result.replace('Y',yreplace,1)
	
	print("Case #"+str(case)+": "+result)

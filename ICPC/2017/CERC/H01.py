nodes = []

nodes.append( [ "", 0, [], "/" ] )

n = int(input())
for i in range(n):
	s,siz = input().split(' ')
	siz = int(siz)
	pth = s.split('/')[1:]
	ind = 0;
	for level in range(len(pth)):
		for ch in nodes[ind][2]:
			if nodes[ch][0] == pth[level]:
				nodes[ind][1] += siz
				nodes[ch][3] = nodes[ind][3] + pth[level] + "/"
				ind = ch
				break
		else:
			nodes[ind][2].append(len(nodes))
			nodes[ind][1] += siz
			nodes.append( [pth[level], 0 if level<len(pth)-1 else siz, [], nodes[ind][3] + pth[level] + "/" ] )
			ind = len(nodes)-1
	
limit = int(input())

#for i,no in enumerate(nodes):
	#print(i,no)

out = []

def pr(ind):
	if len(nodes[ind][2]) == 0:
		return
	chprint = False
	for ch in nodes[ind][2]:
		if nodes[ch][1] >= limit:
			chprint = True
			break
	lastdir = True
	for ch in nodes[ind][2]:
		if len(nodes[ch][2]) > 0:
			lastdir = False
	
	strch = '#'
	if lastdir:
		stch = '#'
	elif chprint:
		stch = '-'
	else:
		stch = '+'
	out.append(' '.join([nodes[ind][3], str(nodes[ind][1]), str(stch)]))
	#print(stch, nodes[ind][3], nodes[i][1])
	if chprint:
		for ch in nodes[ind][2]:
			pr(ch)


pr(0)

#print('out:', out)
out.sort()
for o in out:
	s = o.split(' ')
	print(' '.join([' ' if s[2]=='#' else s[2], s[0], s[1]]))

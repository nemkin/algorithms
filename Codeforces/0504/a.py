import sys

n = int(input())
degs = [None]*n
xors = [None]*n
degsdict = {}
for i, l in enumerate(sys.stdin.read().splitlines()[:n]):

    d, xors[i] = map(int, l.split())

    degs[i] = d   
 
    if not d in degsdict:
        degsdict[d] = set()
    
    degsdict[d].add(i)

edges = []

if not 1 in degsdict:
    print(0)
    sys.exit()

while degsdict[1]:

    v = degsdict[1].pop()
    n = xors[v]
    edges.append([v, n])

    ndeg = degs[n]
    degsdict[ndeg].remove(n)

    ndeg -= 1
    if not ndeg in degsdict:
        degsdict[ndeg] = set()

    degsdict[ndeg].add(n)
    degs[n] -= 1

    xors[n] = xors[n] ^ v

print(len(edges))
print("\n".join([" ".join(map(str, i)) for i in edges]))


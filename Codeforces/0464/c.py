import sys

modulo = 1000000007

def mod_pow(num, pow):

    res = 1
    sq = num%modulo

    while 0<pow:
    
        if(pow&1):
            res=(res*sq)%modulo

        sq = (sq*sq)%modulo

        pow = pow>>1

    return res

repnum = [None]*11
replen = [None]*11

repnum[10] = -1
replen[10] = -1

for i in range(10):

    repnum[i] = i
    replen[i] = 1


inputlines = sys.stdin.read().split('\n')

linenum = int(inputlines[1])

querydigit = [None] * (linenum+1)
querynumstr = [None] * (linenum+1)

querydigit[0] = 10
querynumstr[0] = inputlines[0]

for i in range(2,2+linenum):

    qd, qns = inputlines[i].split("->")
    querydigit[i-1] = int(qd)
    querynumstr[i-1] = qns 

for i in range(len(querydigit)-1, -1, -1):

    resultnum = 0
    resultlen = 0

    for ii in range(len(querynumstr[i])):

        digit = int(querynumstr[i][ii])

        resultnum = (resultnum * mod_pow(10,replen[digit])) % modulo
    
        resultnum = (resultnum + repnum[digit]) % modulo 

        resultlen = resultlen + replen[digit]

    repnum[querydigit[i]] = resultnum
    replen[querydigit[i]] = resultlen

print repnum[10]

import sys

# listindexes is sorted
def removeat(string, indexes):

    return [c for i, c in enumerate(string) if i not in indexes]

def contains(string, what):

    if not len(what):
        return True
    if not len(string):
        return False

    checked = 0
    for c in string:
        if what[checked] == c:
            checked += 1
            if checked == len(what):
                break

    return checked == len(what)

string = list(input())
what = list(input())
indexes = [i-1 for i in map(int, input().split())]

first = 0
last = len(indexes)-1

while first<last:

    midpoint = first + (last - first)//2 + (last - first)%2
    
    if contains(removeat(string, set(indexes[:midpoint])), what):
        first = midpoint
    else:
        last = midpoint-1

print(first)


from collections import Counter
a = list(map(int, [input(), input()][1].split()))
print( len(a) - Counter(a).most_common(1)[0][1] )

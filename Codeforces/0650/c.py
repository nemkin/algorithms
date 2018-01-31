n,m = map(int, input().split())
table = [list(map(int, input().split())) for i in range(n)]
rev = {k: v for v, k in enumerate(sorted(list(set([item for sublist in table for item in sublist]))))}
print(list(map(lambda row: list(map(lambda element: str(rev[element]+1), row)), table)))


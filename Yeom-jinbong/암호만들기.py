from itertools import combinations
L, C = map(int, input().split())
sol=list(input().split())
sol=sorted(sol)
sol2=combinations(sol,L)
sol2=list(sol2)
sample=['a','e','i','o','u']
sample=set(sample)
index=0
result = []
for i in sol2:
  i=set(i)
  v=L-len(i&sample)
  g=L-v
  if v<2 or g<1:
    continue
  else:
    result.append(i)
for i in result:
  i = list(i)
  i.sort()
  q=''.join(i)
  print(q)

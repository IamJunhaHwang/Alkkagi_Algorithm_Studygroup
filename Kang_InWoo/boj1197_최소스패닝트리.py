from sys import stdin
v, e = map(int, stdin.readline().split())
abc = [tuple(map(int,stdin.readline().split())) for _ in range(e)]
        
# 크루스칼
abc.sort(key=lambda x:x[2]) # 간선을 가중치 순으로 정렬
vset = [ {i} for i in range(1,v+1)] # 정점 집합 초기화. 처음엔 모든 정점이 하나의 집합

res = 0
for edge in abc:
    u,v,w = edge
    for i in range(len(vset)):
        if u in vset[i]:
            aidx = i
        if v in vset[i]:
            bidx = i
        
    if aidx != bidx:    # 정점 u,v가 다른 집합에 속하면(사이클이 안생긴다면)
        res += w
        bset = vset[bidx]  
        aset = vset.pop(aidx)
        vset.remove(bset)
    
        vset.append(aset|bset)  # 두 정점 집합을 하나로 합침
        
print(res)

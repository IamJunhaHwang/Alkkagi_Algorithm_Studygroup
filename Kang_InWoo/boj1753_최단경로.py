from sys import stdin, maxsize
from heapq import heappush, heappop  # 최소 힙 구현

v, e = map(int, stdin.readline().split())
k = int(input())    # 시작 정점
uvw = [list(map(int,stdin.readline().split())) for _ in range(e)]   #input() 쓰면 시간초과 남

# 시작 정점 별로 간선을 묶어준다. (인접행렬로 표현하면 메모리초과 -최대 4*10^8 )
graph = [[] for _ in range(v+1)]
for edge in uvw:
    graph[edge[0]].append(edge[1:3])
    
    
# 음의 가중치를 허용하지 않는 그래프의 최단거리 - 다익스트라
dis = [maxsize for _ in range(v+1)]   # d[3]: 시작 정점에서 정점3까지 최단거리. 처음에 무한(최대값)로 초기화
dis[k] = 0
mheap = [[0, k]]    # 힙에 시작 정점 넣기
    
while mheap:
    currw, currv = heappop(mheap)   # 가중치가 가장 작은 정점 pop
    
    if currw > dis[currv]:   # 현재 알려진 거리보다 길면 continue
        continue
    
    for newv, neww in graph[currv]:   # 시작 정점이 currv인 간선에 대해
        total = currw + neww 
        if total < dis[newv]:    # 해당 노드를 거처갈 때의 거리(total)가 알려진 거리보다 작으면 dis갱신
            dis[newv] = total
            heappush(mheap, [total, newv])  # 갱신된 가중치와 정점을 힙에 push
            
for i in dis[1:]:   # dis[1]부터 출력해서 범위 맞춤
    print("INF" if i == maxsize else i)

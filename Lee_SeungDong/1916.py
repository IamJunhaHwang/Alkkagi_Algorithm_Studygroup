import sys
from heapq import heappush, heappop

input = sys.stdin.readline
Bus = int(input())
Route = int(input())

max_int = 100000000
graph = [[] for i in range(Bus+1)]
dijkstra = [max_int for i in range(Bus+1)]
heap = []

for i in range(Route):
    ide, iar, iweight = map(int, input().split())
    graph[ide].append([iar, iweight]) #인접리스트 or 인접배열
de, ar = map(int, input().split())

dijkstra[de] = 0
heappush(heap, [0, de])

while heap:
    weight, node = heappop(heap)
    if node == ar:
        break #도착 노드의 최소 가중치를 찾으면 종료
    if dijkstra[node] < weight:
        continue #최소 가중치를 본 노드는 넘김
    for n_node, e_weight in graph[node]:
        n_weight = weight + e_weight
        if dijkstra[n_node] > n_weight: #갱신이 되면 heap에 넣어줌
            dijkstra[n_node] = n_weight
            heappush(heap, [n_weight, n_node])

print(dijkstra[ar])
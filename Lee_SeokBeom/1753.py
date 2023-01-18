import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())

start = int(input())

graph = [[] for _ in range(n + 1)]

distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, input().split())

    graph[a].append((b, c))

def dijkstra(start):
    q = []

    #가장 우선순위가 높은 데이터 먼저삭제, 현재 가장 가까운 노드를 저장하기 위한 목적
    heapq.heappush(q, (0, start))
    distance[start] = 0

    
    #큐가 비어있지 않으면
    while q:
        #가장짧은 거리가 짧은 노드 출력
        dist, now = heapq.heappop(q)
        
        #기존의 경로의 길이가 적다면 넘어감
        if distance[now] < dist:
            continue
        
        #기존의 길이보다 크거나 같은경우

        for i in graph[now]:
            #i[1]은 크기
            cost = dist + i[1]
            
            #현재 노드를 겨처서 이동하는 거리가 짧은 경우 
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)

for i in range(1, n + 1):
    if distance[i] == INF:
        print("INF")
    
    else:
        print(distance[i])
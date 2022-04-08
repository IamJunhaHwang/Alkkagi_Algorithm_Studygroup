Vnum = int(input())
V = list(list() for i in range(0, Vnum, 1))
Enum = int(input())
for i in range(0, Enum, 1):
    a, b = input().split()
    a = int(a) - 1; b = int(b) - 1
    V[a].append(b)
    V[b].append(a)
visit = list() #방문 표시
stack = list() #dfs를 위한 스택
stack.append(0) #우선 시작 노드를 스택에 삽입
while stack: #스택이 빌 때까지 반복
    node = stack.pop() #pop하여 노드 확인
    if node not in visit: #방문 안했으면
        visit.append(node) #체크하고
        stack.extend(V[node]) #그 노드와 연결된 노드를 스택에 삽입
print(len(visit)-1)
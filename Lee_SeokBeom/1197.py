import sys
input = sys.stdin.readline

#사이클의 존재여부를 찾기 위해 부모노드 찾기
#부모가 같을 경우 사이클이 존재하는 것을 의미
def find_parent(parent, x):
    #parent[x]의 값이 자기자신이 아닐경우 부모가 있다는 의미이므로
    #재귀방식으로 찾음
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

#연결을 위해서 부모노드를 같게 만들어줌
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    #부모노드가 작은 것을 우선시하게 함
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

v, e = map(int, input().split())

#부모노드
parent = [0] * (v+1)

#입력 받은 간선
edges = []

#처음 부모노드의 값을 자기자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

for _ in range(e):
    a, b, cost = map(int, input().split())

    #cost부터 하는 이유는 cost순으로 정렬하기 위함
    edges.append((cost, a, b))

#정렬
edges.sort()

result = 0
for edge in edges:
    cost, a, b = edge
    #부모가 같으면 사이클이 생김
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

print(result)

import sys
a, b = map(int,sys.stdin.readline().split()) 

class Node(object): #노드: 데이터,부모노드
    def __init__(self, data, parent):
        self.data = data
        self.parent = parent
        
tree = [[Node(a, None)]]
lv = 0
check = [0 for _ in range(100001)] #중복되는 가지를 생성안하기위한 리스트(메모리 초과방지)
if a>=b:
    print(a-b)
    print(*range(a,b-1,-1))

else:
    while(1):
        tree.append([])
        for r in tree[lv]:
            d = r.data
            op = [x for x in [d-1, d+1, d*2] if x>=0 and x<=100000 and check[x]==0 ]            
            if b in op: #b(동생)위치 까지 도착 -> 루트까지 거슬러 올라가며 정답출력
                route = [b]
                for _ in range(lv+1):
                    route.append(r.data)
                    r = r.parent
                print(lv + 1)
                print(*reversed(route))
                sys.exit()
            tree[lv+1].extend([Node(x,r) for x in op])  #자식노드를 다음 레벨에 추가
            check[d]=1
        lv +=1

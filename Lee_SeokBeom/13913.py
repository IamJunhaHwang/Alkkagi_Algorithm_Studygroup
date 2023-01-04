from collections import deque

n, k = map(int, input().split())

#pypy3로 해야 시간 초과가 안나는듯 함
#가장빠른 시간을 구하기 위해 너비우선 탐색인 bfs를 사용
def bfs():
    #큐를 사용하여 너비우선탐색을 사용할 수 있음
    q = deque()
    q.append(n)
    depth = [0] * 100001 #깊이 즉 걸린시간을 알기위해 사용
    node = [0] * 100001 #이전 노드 탐색시 사용
    while q:
        x = q.popleft()
        if x == k:
            print(depth[k])
            break
        else:
            #너비우선탐색이므로 -1,1,*2한 값을 이전 큐보다 뒤에 놔야하므로 append
            for i in (x-1, x+1, x*2):
                if 0<=i<=100000 and depth[i] == 0:
                    depth[i] = depth[x] + 1
                    node[i] = x
                    q.append(i)

    path_list = []
    tmp = x
    #path가 5 4 8 16 17 순서일때
    #node[17] = 16, node[16] = 8 ... node[4] = 5, node[5] = 0을 만족하므로 역으로 찾음
    for i in range(depth[k]+1):
        path_list.append(tmp)
        tmp = node[tmp]
    #역으로 값이 들어가기때문에 reverse를 함
    path_list.reverse()
    #출력시 자동으로 띄어쓰기함
    print(*path_list)
        

bfs()
dx = (1, 2, 2, 1, -1, -2, -2, -1)
dy = (2, 1, -1, -2, -2, -1, 1, 2) #8방향 이동

def isin(x, y, N): #체스판 안에서 벗어나지 않았는지 확인
    if (x>=0 and y>=0):
        if (x<N and y<N):
            return True
    return False

T = int(input())
for t in range(T):
    N = int(input())
    sx, sy = input().split()
    sx = int(sx)
    sy = int(sy)
    ax, ay = input().split()
    ax = int(ax)
    ay = int(ay)

    queue = list() #큐 초기화
    chess = [[0 for col in range(N)] for row in range(N)] #체스판 초기화
    chess[sx][sy] = 1 #시작지점 표시
    queue.append((sx, sy))
    pre = 1
    cur = 0
    while(pre != cur): #BFS
        x, y = queue[cur][0], queue[cur][1]
        cur += 1
        for i in range(8):
            nx, ny = x+dx[i], y+dy[i]
            if(isin(nx, ny, N)):
                if(chess[nx][ny] == 0):
                    chess[nx][ny] = chess[x][y] + 1 #1씩 늘려주면서 저장
                    queue.append((nx, ny))
                    pre += 1
        if(x==ax and y==ay): #탐색완료 전에 목적지 도착
            print(chess[x][y]-1)
            break
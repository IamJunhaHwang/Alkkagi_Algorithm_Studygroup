N, EP, WP, SP, NP = map(int, input().split())
P = (EP/100.0, WP/100.0, SP/100.0, NP/100.0)
x = (1, -1, 0, 0)
y = (0, 0, -1, 1)
visit = [[False for i in range(29)] for i in range(29)]

def crazybot(X, Y, N):
    if N == 0:
        return 1.0
    result = 0.0
    visit[X][Y] = True
    for i in range(4):
        nx = X + x[i]
        ny = Y + y[i]
        if visit[nx][ny]:
            continue
        else:
            result += P[i]*crazybot(nx, ny, N-1)
    visit[X][Y] = False
    return result

final_result = crazybot(N, N, N)
print('{:0.9}'.format(final_result))
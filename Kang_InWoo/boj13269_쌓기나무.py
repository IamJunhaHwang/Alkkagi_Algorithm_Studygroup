import sys
N,M = map(int, input().split())
up = [list(map(int,input().split())) for _ in range(N)]
front, right = list(map(int,input().split())),list(map(int,input().split()))

 # 앞, 옆을 고려한 최대배치. 마지막에 up[i][j]곱해서 블록 없는 위치는 0
res = [[min(front[j],right[N-1-i]) * up[i][j] for j in range(M)] for i in range(N)]  

# 정답이 입력과 맞는지 다시 확인 ex) front가 [1 100 10] -> max(res[0][0],res[1][0])은 1, max(res[0][1],res[1][1])은 100 ...
for j in range(M):
    if max([res[i][j] for i in range(N)]) != front[j]:
        print(-1)
        sys.exit()
for i in range(N):
    if max([res[i][j] for j in range(M)]) != right[N-1-i]:
        print(-1)
        sys.exit()

for i in res: # 조건에 걸리는게 없으면 정답 출력
    print(*i)
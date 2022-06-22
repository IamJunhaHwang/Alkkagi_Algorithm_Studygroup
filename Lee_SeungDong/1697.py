from collections import deque
INT_MAX = 100001 #입력 최대치

N, K = map(int, input().split())
queue = deque()
check = [INT_MAX for i in range(0, INT_MAX, 1)]
check[N] = 0 #시작점 초기화

def isin(i): #리스트의 인덱스 범위를 벗어나지 않기 위한 함수
    if i >= 0:
        if i < INT_MAX:
            return True
    return False

if N==K: #답이 0인 경우 예외 처리
    print(0)

else:
    queue.append((N, 0)) #BFS 시작
    #시작을 K로 해서 홀수인 경우는 /2를 안하는 방법 이용 시
    #큐에 들어갈 숫자를 더 줄일 수 있음

    while queue:
        position, time = queue.popleft()
        npp = position + 1
        npm = position - 1
        np2 = position * 2
        nt = time + 1
        if npp == K or npm == K or np2 == K: #K에 도달하면 종료
            print(nt)
            break

        if position == 0: #현위치가 0이면 +1만 가능
            if check[npp] > nt:
                queue.append((npp, nt))
                check[npp] = nt
            continue
        
        #인덱스 확인 후, check를 통해 최소로 갱신되는지 확인
        if isin(np2) and check[np2] > nt:
            queue.append((np2, nt))
            check[np2] = nt
        if isin(npp) and check[npp] > nt:
            queue.append((npp, nt))
            check[npp] = nt
        if isin(npm) and check[npm] > nt:
            queue.append((npm, nt))
            check[npm] = nt
#참조 https://velog.io/@ttc1018/%EB%B0%B1%EC%A4%80-1686-%EB%B3%B5%EB%82%A0-Python-%ED%8C%8C%EC%9D%B4%EC%8D%AC-BFS

from math import *
from collections import *

#거리 구하는 함수 람다로 처리
cal_dir = lambda x, y, a, b: sqrt((x-a)**2 + (y-b)**2)

#좌표값은 모두 실수이므로 float로 받음
v, m = map(float, input().split())

startX, startY = map(float, input().split())

endX, endY = map(float, input().split())

bunkers = []

#입력받는 문자의 개수를 모르므로 엔터를 받으면 나오게 함
while True:
    try:
        #temp가 공백이면 break
        temp = input()
        if not temp:
            break
        x, y = map(float, temp.split())
        bunkers.append((x, y))
    #입력끝이면 break
    except EOFError:
        break

#닭이 잡히는 마지노선의 시간 '초'로 계산
chickenDieTime = v * 60 * m

#벙커가 들어간 벙커인지 확인하기 위해 set함수 사용
visited = set()


q = deque([(startX, startY, 0)])

#닭이 현재 위치에서 움직일 수 있는 공간은 원형의 형태로 bfs로 탐색
while q:
    x, y, cnt = q.popleft()
    #지금 현재 있는 위치에서 도착지점으로 시간내로 갈수 있을 경우 갔던 벙커의 개수를 출력
    if cal_dir(x, y, endX, endY) < chickenDieTime:
        print('Yes, visiting {} other holes.'.format(cnt))
        break
    
    for bunker in bunkers:
        bx, by = bunker
        #벙커를 지나지 않았고 현재 위치에서 벙커의 위치가 시간내로 갈수 있을 경우 visited방문하고 q에 넣음
        if bunker not in visited and cal_dir(x, y, bx, by) < chickenDieTime:
            visited.add(bunker)
            q.append((bx, by, cnt+1))
#닭이 도착하지 않았을 경우
else:
    print('No.')

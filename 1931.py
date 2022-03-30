N = int(input())
time = list() #회의 시간을 넣을 리스트
for i in range(0, N, 1):
    start, finish = input().split()
    time.append((int(finish), int(start))) #리스트 안에 튜플로 종료시간, 시작시간 저장
time.sort() #종료시간을 우선으로 오름차순 정렬
count = 1 #제일 앞의 회의는 무조건 함
last = time[0][0] #최근에 끝난 회의시간
for i in range(1, N, 1):
    if last <= time[i][1]: #회의 시작시간과 last를 비교
        count += 1
        last = time[i][0] #last를 회의 종료시간으로 갱신
print(count)
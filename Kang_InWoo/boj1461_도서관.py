from sys import stdin

n, m = map(int, input().split())
books = list(map(int,stdin.readline().split()))
res = 0 # 정답. 총 걸음 수

books.sort()
#마지막 음수인덱스 구하기
lidx =-1     
for i in range(n):
    if books[i]>0:
        lidx = i-1
        break
    lidx=i
ridx = lidx+1   # 양수 시작 인덱스

# 리스트 범위를 벗어나지 않는 선에서 양 끝에 부터 +-m만큼의 위치에 있는 책위치의 절대값을 차례로 더한다

for _ in range(1):  #양수 쪽 걸음 더하기
    if ridx==n: break #리스트에 양수가 없을 때
    mov = n-1   #다음에 이동할 책의 인덱스. 가장 큰수부터 시작
    while mov >= ridx: 
        res+= 2 * books[mov]
        mov -= m
    
for _ in range(1):  #음수 쪽 걸음 더하기
    if lidx==-1: break  #리스트에 음수가 없을 때
    mov = 0 #다음에 이동할 책의 인덱스. 가장 작은 수부터 시작
    while mov <= lidx:
        res += 2 * -books[mov]
        mov += m

#더 큰 절대값 갖고 있는 쪽이 마지막에 편도 걸음->마지막 값 빼주기
if -books[0] > books[n-1]:  res-=-books[0]
else:                       res-= books[n-1]
        
print(res)

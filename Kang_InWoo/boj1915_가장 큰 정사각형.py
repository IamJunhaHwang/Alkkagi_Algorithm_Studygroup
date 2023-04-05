n,m =   map(int, input().split())
mat = [list(map(int,list(input()))) for _ in range(n)]   

dp = [[0]*(m+1) for _ in range(n+1)] #2차원 리스트 0으로 초기화. +1씩 해주는건 반복문 첫줄에서부터 이전원소에 접근하기 위함
# dp[i][j]는 mat[i][j]를 오른쪽밑 꼭짓점으로한 정사각형 변의 최대길이

#mat[i-1][j-1]를 꼭짓점으로한 정사각형 변의 최대길이 - 대각, 위, 왼쪽 원소 중 작은 값 (3개 중에서 나머지 변이 길어도 그 길이 이상의 정사각형을 못만듬)
#-> dp배열에서 대각, 위, 왼쪽 원소가 모두 x이면 dp[i][j] = x+1 
for i in range(1, n+1):
    for j in range(1, m+1):
        if mat[i-1][j-1]==1:
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1
        
print(max(map(max, dp))**2)
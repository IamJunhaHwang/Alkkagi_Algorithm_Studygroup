a,b = ' '+input(), ' '+input()  #배열이랑 범위 맞추려고 앞에 공백 하나씩 넣었다.

dp = [[0]*(len(b)) for _ in range(len(a))] #2차원 리스트 0으로 초기화. dp[i][j]는 이전을 포함한 공통 부분 문자열 길이

for i in range(1, len(a)):
    for j in range(1, len(b)):
        if a[i] == b[j]:    # 같은 문자를 만났을 때 이전까지의 공통길이 +1
            dp[i][j] = dp[i-1][j-1] +1
            
print(max(map(max, dp)))

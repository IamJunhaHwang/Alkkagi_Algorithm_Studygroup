first_word = input()
second_word = input()

#이중 리스트를 만들어 가로는 first_word, 세로는 second를 만듦
dp = [[0] * (len(second_word)+1) for _ in range(len(first_word)+1)]

result = 0
for i in range(1, len(first_word)+1):
    for j in range(1, len(second_word)+1):
        #1부터 시작하므로 1을 빼야함, 같은 문자일 경우 위치에 있는 부분의 대각선 값에 1을 더함
        if first_word[i-1] == second_word[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
            #max(dp)는 값이 안나옴
            result = max(result, dp[i][j])

print(result)
n = int(input())
wine_list = [0]
dp = [0]

for i in range(n):
    wine_list.append(int(input()))


dp.append(wine_list[1])

for i in range(2, n + 1):
    if i == 2:
        dp.append(wine_list[1] + wine_list[2])
    else:
        dp.append(max(dp[i - 1], dp[i - 3] + wine_list[i - 1] + wine_list[i], dp[i - 2] + wine_list[i]))
print(dp[n])

#dp[4] ==  경우의 수 (12 13 23)dp[3], (134)dp[1]+wine[3]+wine[4],  (124) dp[2] + wine[4]
#dp[i] == dp[i-1], dp[i-3]+wine[i-1]+wine[i], dp[i-2]+wine[i] 

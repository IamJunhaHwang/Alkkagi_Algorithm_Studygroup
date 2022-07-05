N = int(input())

dptable = [[0 for i in range(10)] for j in range(N)]
for i in range(10):
    dptable[0][i] = 1 #dptable 초기화, N이 1일 때 초기값 지정

for i in range(1, N):
    for j in range(10):
        for k in range(j+1):
            dptable[i][j] += dptable[i-1][k]
#점화식으로 계산하면서 표채우기

count = 0

for i in range(10):
    count += dptable[N-1][i]
count %= 10007
#원하는 값 만들기
print(count)
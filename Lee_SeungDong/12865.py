N, K = map(int, input().split())
WV = list()
dptable = [[0 for x in range(K+1)] for x in range(N)]

for n in range(N):
    W, V = map(int, input().split())
    WV.append((W, V))
WV.sort() #무게 오름차순으로 정렬

for j in range(K+1): #talbe 첫 row 설정
    if WV[0][0] <= j:
        dptable[0][j] = WV[0][1]

for i in range(1, N):
    for j in range(1, K+1):
        if WV[i][0] > j:#해당 row label보다 column label 값이 더 작으면 한 칸 아래의 값으로 설정
            dptable[i][j] = dptable[i-1][j] 
        else:
            dptable[i][j] = max(dptable[i-1][j], dptable[i-1][j-WV[i][0]]+WV[i][1])
#그 외에는 한 칸 아래와 해당 row label의 weight를 뺀 dptable의 값에 해당 row의 value를 더한 값을 비교

print(dptable[N-1][K])
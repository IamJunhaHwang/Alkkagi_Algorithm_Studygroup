N = int(input())

dptable = [[0 for i in range(3)] for i in range(N)]

dptable[0][0] = 1 #dptable의 0열은 사자가 i행에 없을 때
dptable[0][1] = 1 #dptable의 1열은 사자가 i행의 왼쪽에 있을 때
dptable[0][2] = 1 #dptable의 2열은 사자가 i행의 오른쪽에 있을 때

for i in range(1, N):
    dptable[i][0] = (dptable[i-1][0] + dptable[i-1][1] + dptable[i-1][2])%9901
    dptable[i][1] = (dptable[i-1][0] + dptable[i-1][2])%9901
    dptable[i][2] = (dptable[i-1][0] + dptable[i-1][1])%9901

print((dptable[N-1][0]+dptable[N-1][1]+dptable[N-1][2])%9901)
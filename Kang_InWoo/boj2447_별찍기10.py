n = int(input())
"""
3 x 3 기본패턴을 차례로 그리는게 어려우므로 
처음에 n x n 2차원 배열을 *로 채우고 빈칸' '이 들어갈 자리를 찾는다
"""
arr = [list('*'*n) for _ in range(n)]   # *로 채운 2차원 리스트

# 시작 좌표(x,y)를 포함한 kxk 사각형 영역을 공백으로 변환
def replb(x,y,k):
    for i in range(k):
        arr[x+i][y:y+k]=' '*k
        
# 3x3패턴의 빈칸 찾기: (1,1),(1,4),(1,7)...(4,1),(4,4),(4,7)... -> +3,+3
# 9x9패턴의 빈칸 찾기: (3,3),(3,12),(3,21)...,(12,3),(12,12)... -> +9,+9    pxp패턴의 다음 빈칸은 (x,y+p)로 일반화가능
p =3    #p: 현재 공백을 찾는 패턴길이 3x3 -> 9x9 -> 27x27
while (p<=n):
    for i in range(p//3,n,p):
        for j in range(p//3,n,p):
            replb(i,j,p//3)     
    p *= 3

for i in range(n):
    print(''.join(arr[i]))
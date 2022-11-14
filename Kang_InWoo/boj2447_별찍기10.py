#n = int(input())

"""
3 x 3 기본패턴을 차례로 그리는게 어려우므로 
처음에 n x n 2차원 배열을 *로 채우고 빈칸이 들어갈 자리를 찾는다
"""
n = 27
arr = [list('*'*n) for _ in range(n)]   # *로 채운 2차원 리스트

# 시작 좌표(i,j)의 kxk 사각형 영역을 공백으로 변환
def replb(i,j,k):
    for _ in range(k):
        pass
        
    
# # 3x3패턴의 빈칸 찾기: (1,1),(1,4),(1,7)...(4,1),(4,4),(4,7)... -> (1+3n,1+3n)좌표는 모두 빈칸
for i in range(1,n,3):
    for j in range(1,n,3):
        arr[i][j]=' '
        
    
# 9x9패턴의 빈칸 찾기
for i in range(3,n,9):
    for j in range(3,n,9):
        pass        

for i in range(n):
    print(''.join(arr[i]))
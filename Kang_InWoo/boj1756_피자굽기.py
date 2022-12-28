import sys
d, n = map(int,sys.stdin.readline().split())
o = list(map(int,sys.stdin.readline().split()))
p = list(map(int,sys.stdin.readline().split()))

# 피자가 지름보다 더 작은 관을 통과할 수 없으므로 이전 지름보다 큰 오븐의 지름을 이전값으로 바꿔놓고 생각
# (이렇게 하면 피자가 최상단부터 맞는 위치까지 들어가는 과정을 생략하고 반복문을 한번만 돌릴 수 있음)
for i in range(1,d):    
    o[i] = min(o[i-1],o[i])

# 오븐 최하단 부터 현재 인덱스의 피자가 들어갈 위치를 찾는다
pidx = 0
for i in range(d-1, -1, -1):    
    if p[pidx] <= o[i]:
        if pidx == n-1: 
            print(i+1)
            sys.exit(0)
        pidx+=1

print(0) # 반복문이 모두 돌면 최상단까지도 피자가 들어갈 자리가 없다
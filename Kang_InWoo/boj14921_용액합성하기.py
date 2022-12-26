from sys import stdin

n = int(input())
l = list(map(int,stdin.readline().split()))
l.sort()

ridx =-1     # 양수시작 인덱스
for i in range(n):
    if l[i]>=0:
        ridx = i
        break
    
# 양수가 없을 때, 음수가 없을 때
if ridx==-1:    print(l[n-2]+l[n-1])
elif ridx == 0: print(l[0]+l[1])

# 음수 원소와 양수 원소를 조합해서 절대값이 가장 작은 조합을 찾음
else:
    res = l[0]+l[1]
    for i in range(0,ridx):           
        last = 9223372036854775807
        case = 0
        for j in range(ridx,n):    
            case = l[i]+l[j]
            if abs(case) > abs(last):   # 합의 절대값이 더 커지는 경우엔 반목문 멈춰도 됨
                case = last
                break 
            last = case
        if abs(case) < abs(res):    res = case
        
    # 정답후보 중에서 최소 절대값을 찾음 (음수, 양수끼리 더한 합이 정답이 될수 있어서 추가)
    can = [res] 
    if ridx>=2: can.append(l[ridx-2]+l[ridx-1])
    if n-ridx >= 2: can.append(l[ridx]+l[ridx+1])
    canabs = list(map(abs,can))
    print(can[canabs.index(min(canabs))])


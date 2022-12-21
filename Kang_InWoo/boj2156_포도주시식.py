n = int(input())
l = [int(input()) for _ in range(n)]

if n<3:    print(sum(l))    # 두잔 이하일때는 그냥 더하면됨

else:
    t = [0, l[0],l[0]+l[1]] + [0 for _ in range(n-2)]  # t[i] = i잔 까지 고려한  최대값
     
    for i in range(2,n):
        t[i+1] = max(
            t[i],                       # 이번 잔은 안 마심          
            t[i-1] + l[i],              # 이번잔을 마시되 이전잔은 안마심
            t[i-2] + l[i-1] + l[i]      # 이번잔과 이전잔을 마심
        )
    print(t[n])

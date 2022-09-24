from sys import stdin


arrs = [list(map(int,stdin.readline().split())) for i in range(4)]

for arr in arrs:
    if arrs.index(arr)!=0:  print(' ', end=' ')
    
    #1)총승리수(인덱스를 3으로 나눴을때 첫번째 원소의 합) - 총패배수가 0이 아닐때
    if (sum(arr[0::3]) - sum(arr[2::3])) != 0:   
        print(0,end='[1]')
        continue
    
    #2) 6이 입력될 수 있다고 되있지만 팀당 5경기만 하기 때문에 불가능하다
    if 6 in arr:    
        print(0,end='[2]')
        continue
    
    #3) 무승부 개수를 조합해서 0이 나올 수 있어야함 
    drw = 0
    for i in range(0,18,3):   # 변수 drw가 0이하 일때 + 아니면 -, 마지막에 0이되면 통과
        if arr[i+1]==0:    continue
        if drw<=0:  drw += arr[i+1]
        else:       drw -= arr[i+1]
    if drw!=0: 
        print(0,end='[3]')
        continue

    #4) 각 팀당 승 무 패 숫자의 합은 5여야 한다
    try:
        for i in range(0,18,3):  
            if sum(arr[i:i+3:1]) != 5:
                print("sum",i,"~",i+3,sum(arr[i:i+3:1]))
                print(0,end='[4]')
                raise Exception()
    
    except:         #예외처리로 틀렸을 때 바로 바깥반복문에서 continue되도록
        continue
    
    else:
        print(1,end='')    
        
    
    # 무승부, 승-패 수 맞추는 조건필요
    # 반례  1 4 0 0 4 1 2 2 1 1 2 2 4 0 1 1 0 4
    #       5 0 0 2 3 0 2 2 1 1 1 3 1 1 3 0 1 4
    
    
    
        
    
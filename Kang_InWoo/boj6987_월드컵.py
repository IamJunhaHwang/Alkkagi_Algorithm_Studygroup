from sys import stdin

arrs = [list(map(int,stdin.readline().split())) for i in range(4)]

"""
무승부 개수 리스트로 가장 큰원소(팀)의 경기를 차례로 지워서 최종적으로 [0] 형태가 나올수 있어야함.
ex) 
[5,4,1,0,0,0] -> 5무승부인 팀과 무승부가 0인팀이 같이 있을 수 없으므로 처음부터 불가능한 형태
[4,4,2,1,1,0] -> [3,1,0,0,0] -> 3과 함께 지울수 있는 경기가 다른팀에 없으므로 불가능한 형태
"""
def drw(lis):
    for i in range(5):
        p = lis.pop(0)
        if p>len(lis):  return False    #런타임 오류방지, 오답 입력되면 리스트범위 넘어갈수있음
        for j in range(p):  lis[j]-=1
        lis.sort(reverse=True)
        if -1 in lis:   return False
    if lis[0]!=0: return False
    return True

def findidx(lis,n): #리스트에서 n번째로 큰수의 인덱스 반환 + 중복 방지
    lisc = lis.copy()
    idx = 0
    for i in range(n):
        bigst = max(lisc)
        idx = lisc.index(bigst)        
        lisc[idx]= -1
    return idx

"""
승리수리스트, 패배수리스트를 받아
승리수와 타팀의 패배수를 하나씩 깜
최종적으로 패배 리스트는 [0,0,0,0,0,0]혹은 1만남아있는 형태가 되야함
"""
def winlose(w,l):
    for i in range(6):
        er =[]  # 패배 리스트에서 지울 인덱스
        mw = findidx(w,i+1) # w에서 i번쨰로 큰수
        if w[mw] == 0: break
        tmp = l.copy()      # l에서 최대값을 차례대로 찾기위해 복사한 임시 리스트
        tmp[mw]=-1          # 현재 승리를 지우는 같은팀에서 최대값이 안나오도록
        for j in range(w[mw]):
            eridx = findidx(tmp,j+1)
            er.append(eridx)
        for j in er: l[j]-=1
        
        if min(l)<0:    return False
        if min(l)==0 and max(l)==1: return True
    if l.count(0)!=6: return False
    return True

for arr in arrs:            
    #1) 총 승리 수 = 총 패배 수
    if (sum(arr[0::3]) - sum(arr[2::3])) != 0:   
        print(0,end=' ')
        continue
    
    #2) 각 팀당 승 무 패 개수 합은 5
    try:
        for i in range(0,18,3):  
            if sum(arr[i:i+3:1]) != 5:
                print(0,end=' ')
                raise Exception()
    except:   #예외처리로 틀렸을 때 바깥반복문에서 continue되도록
        continue
    
    #3) 무승부 수 맞추기
    if drw(sorted(arr[1::3],reverse=True))==False:
        print(0,end=' ')
        continue
    
    #4) 승-패 수 맞추기
    if winlose(arr[0::3],arr[2::3])==False:
        print(0,end=' ')
        continue
        
    print(1,end=' ')    

# 틀렸습니다틀렸습니다틀렸습니다틀렸습니다틀렸습니다틀렸습니다틀렸습니다

    
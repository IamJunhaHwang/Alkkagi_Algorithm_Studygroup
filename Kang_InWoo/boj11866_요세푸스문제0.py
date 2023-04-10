n, k = map(int, input().split())
table = list(range(1,n+1))
res = []

p = k -1 # 다음 차례 (table[2]는 3번째 사람)

for _ in range(n):  #사람 수 만큼 반복
    res.append(table[p]) 
    table[p] = -1   #죽은? 사람은 -1로 
    
    if len(res)==n:     break
    
    for _ in range(k):
        p = (p+1) % n # 원형 테이블이니까 마지막 사람을 넘어서면 다시 처음으로
        
        while table[p]==-1: #다음 차례가 죽은 사람이면 산사람이 나올때 까지 ++
            p = (p+1) % n

res =["<"+str(res[0])+","] + [str(res[i])+"," for i in range(1,n-1)] + [str(res[n-1])+">"]

if n==1:    print("<1>")
else:   print(*res)
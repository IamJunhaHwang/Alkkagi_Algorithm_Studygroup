from sys import stdin
from itertools import combinations



l,c = map(int,(stdin.readline().split()))
# 암호길이, 사용가능 문자 개수

valid = stdin.readline().split()
# 유효한 문자리스트

mo = []

for le in 'aeiou':
    if le not in valid: continue;
    mo.append(valid.pop(valid.index(le)))
# mo에 모음, valid에는 자음만 남도록
# print(mo,valid)

res = []

for i in range(1,min(len(mo)+1,l-1)): #i=모음 개수, 자음이 최소2개있어야 하니 모음 최대수는 l-2
    a = list(combinations(mo,i))
    b = list(combinations(valid,l-i))
    
        
    for j in range(len(a)):
        for k in range(len(b)):
            res.append("".join(sorted(a[j]+b[k])))
            # 모음 자음 조합후 문자열 알파벳으로 정렬
res.sort()
#전체 리스트 정렬
for i in res:
    print(i)

            
    

    








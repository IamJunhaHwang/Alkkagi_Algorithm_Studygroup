import sys
from itertools import permutations
n, k = map(int,sys.stdin.readline().split()) 
words = [set(sys.stdin.readline().rstrip()[4:-4]) for _ in range(n)]

if k<5: 
    print(0)
    sys.exit()

def isreadable(word,readable):
    if word<=readable|default: #부분집합(모든 글자를 읽을 수있는지) 판별
        return True
    return False

default = {'a','n','t','i','c'}    
all = set() # 모든 글자 집합 
for w in words:
    all = all.union(w)

all = all-default
if len(all)<=k-5: # 모든 글자보다 배우는 글자가 더 많으면 모든 단어 읽을 수 있음
    print(n)
    sys.exit()

readable=[set(x) for x in permutations(all, k-5)] # 읽을 수 있는 글자 조합 

print('all',all)
print('readable: ',readable)

# 읽을 수 있는 글자 조합 별 읽을 수 있는 단어 개수를 구함
res = [0]*len(readable) + [0]
for i in range(len(readable)):
    for word in words:
        if isreadable(word,readable[i]):    
            res[i] +=1

print(max(res))
    

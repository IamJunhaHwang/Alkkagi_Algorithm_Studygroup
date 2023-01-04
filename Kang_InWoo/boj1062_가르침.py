from sys import stdin
from itertools import combinations
n, k = map(int,stdin.readline().split()) 
words = [set(stdin.readline().rstrip()[4:-4])-{'a','n','t','i','c'} for _ in range(n)] #기본 글자 5개를 제외한 단어들

res =0
if k>=5: # 배우는 글자가 5개 미만이면 어떤 단어도 읽지 못함
    all = set() # (기본글자 제외한) 모든 글자 집합 
    for w in words:
        all = all.union(w)
    if len(all)<=k-5: # 모든 글자보다 배우는 글자가 더 많으면 모든 단어 읽을 수 있음
        res = n

    else: # 읽을 수 있는 글자 조합 별 읽을 수 있는 단어 개수를 구함
        res = 0
        for com in combinations(all, k-5):
            case = 0
            com = set(com)
            for word in words:
                if word<=com:    #부분집합인지(모든 글자를 읽을 수있는지) 판별
                    case +=1
            if case>res:
                res = case
print(res)

import sys
from itertools import combinations
input = sys.stdin.readline

#메모리 초과, 시간초과 실패
# n, k = map(int, input().split())

# if k < 5:
#     print(0)
#     exit()
    
# else:
#     key_list = [[] for _ in range(n)]
    
#     #anta tica의 글자들을 나누면 5개가 나옴
#     #set을 쓰면 in 할때 시간 적게듦
#     alpha_list = set(['a','n','t','i','c'])

#     for i in range(n):
#         tmp_word = input().split()
#         #앞뒤 슬라이스후 set으로 중복삭제후 리스트
#         tmp_word = list(set(tmp_word[0][4:-4]))

#         #알파벳중 alpha_list에 있는 것은 뺌
#         for j in tmp_word:
#             if j in alpha_list:
#                 continue
#             else:
#                #숫자로 조회하기 위해 변경
#                 key_list[i].append(ord(j)-ord('a') + 1)
    
#     result = 0

#     #알파벳 21글자를 조합하여 나오는 리스트
#     #combinations는 iterator 이므로 바로 해야 메모리 초과 안남
#     for comb in combinations(range(1, 26), k-5):
#         print(comb)
#         tmp = 0
#         for key in key_list:
#             tmp += 1
#         result = max(tmp, result)
                
    
#     print(result)

#출처 https://peisea0830.tistory.com/35

n, k = map(int, input().split())

word_list = [0] * n

for i in range(n):
    #마지막에 \n이 들어가는 거 빼줌
    tmp_word = input().rstrip()
    #비트 마스킹 저장
    #abc이면 111, abd 이면 1101
    for j in tmp_word:
        word_list[i] |= (1 << (ord(j) - ord('a')))

#k가 5보다 아래면 0
if k < 5:
    print(0)

#k가 26이면 다 되므로 n, 시간이 줄어듬
elif k == 26:
    print(n)

else:
    need = list("antic")
    other = list("bdefghjklmopqrsuvwxyz")
    result = 0
    #조합된 리스트들에 위와 같이 비트마스킹을 하려고 함
    for comb in combinations(other, k - 5):
        tmp_res = 0
        comb_word = 0

        #필수 문자인 antic를 comb_word에 마스킹
        for i in need:
            comb_word |= (1 << (ord(i) - ord('a')))
        
        #comb 리스트에 담겨진 문자들을 마스킹 a << b a를 b비트만큼 왼쪽으로 시프트
        for i in comb:

            comb_word |= (1 << (ord(i) - ord('a')))

        #input 이었던 word_list의 것들과 비교
        #만약 input이 1101이고 comb_word가 1101이면 &하면 1101 이므로 포함된 단어가 같으면 비트마스크가 같게 나옴
        #만약 input이 1111이고 comb_word가 1101이면 &하면 3번째 값이 없으므로 1101 포함된 단어가 input에는 없고 comb에는 있으면 비트마스크가 다르게 나옴
        #만약 input이 1101이고 comb_word가 1111이면 &하면 1101 이므로 포함된 단어가 input에 단어가 comb에 포함되면 비트마스크가 같게 나옴
        for word in word_list:
            if comb_word & word == word:
                tmp_res += 1
        
        result = max(result, tmp_res)

    print(result)

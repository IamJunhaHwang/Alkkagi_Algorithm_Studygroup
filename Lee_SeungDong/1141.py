N = int(input())
pref = list()
for i in range(0, N, 1):
    elem = input()
    pref.append(elem)
pref.sort(key=len) #문자열 길이를 기준으로 오름차순 정렬
count = 0
for i in range(0, N, 1):
    for j in range(i+1, N, 1):
        if pref[j].startswith(pref[i]): #앞에서부터 문자열이 일치하는지 체크하는 함수
            count += 1 #해당 문자열을 리스트에서 삭제하는 대신에 count를 올려줌
            break
print(N - count) #마지막에 리스트 크기에서 count를 뺌
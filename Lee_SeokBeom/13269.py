n, m = map(int, input().split())

top_list = []

for i in range(n):
    tmp = list(map(int, input().split()))
    top_list.append(tmp)

front_list = list(map(int, input().split()))
right_list = list(map(int, input().split()))

result_list = [[0] * m for _ in range(n)]
max_front_list = [0] * m
#front가 n, right는 m
for i in range(n):
    for j in range(m):
        if top_list[i][j] == 0:
            continue
        else:
            result_list[i][j] = min(front_list[j], right_list[n-1 - i])
            #앞에서 보는 것 체크하기 위해 사용
            max_front_list[j] = max(max_front_list[j], result_list[i][j])

isExist = True

#오른쪽에서 본것 췤
for i in range(n):
    if max(result_list[i]) == right_list[n-1 - i]:
        continue
    else:
        isExist = False

#앞에서 본것 췤
for j in range(m):
    if max_front_list[j] == front_list[j]:
        continue
    else:
        isExist = False

if isExist == False:
    print(-1)

else:
    for i in range(n):
        print(*result_list[i])
    
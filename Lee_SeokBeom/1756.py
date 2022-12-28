import sys
input = sys.stdin.readline

d, m = map(int, input().split())
 
oven_list = list(map(int, input().split()))

#반죽이 늘어나는게 아니므로 위에서부터 잘라서 i+1번째의 크기가 i보다 작거나 같게 만드는 과정
for i in range(len(oven_list)-1):
    if oven_list[i] < oven_list[i+1]:
        oven_list[i+1] = oven_list[i]

pizza_list = list(map(int, input().split()))

#그냥 이중 반복문 돌리면 30만^2= 900억 가량 되므로 적절하지 않음
#피자 인덱스를 이용하여서 아래부터 무조건 쌓이기때문에 오븐리스트로만 반복문 가능

pizza_cur_index = 0
for i in range(len(oven_list)-1, -1, -1):
    if oven_list[i] >= pizza_list[pizza_cur_index]:
        pizza_cur_index += 1
    else:
        continue
    if pizza_cur_index == m:
        print(i+1)
        break
else:
    print(0)
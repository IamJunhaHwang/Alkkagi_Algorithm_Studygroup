import sys
input = sys.stdin.readline

#최대 100억이므로 combination 사용x
n = int(input())

a_list = list(map(int, input().split()))


left = 0
right = len(a_list)-1
#임의의 최댓값
sum = int(10**10) + 1
check_x = 0
check_y = 0

while True:
    #왼쪽인덱스가 오른쪽인덱스를 넘거나 sum이 0이면 나감
    if left == right or sum == 0:
        break

    if abs(sum) > abs(a_list[left]+a_list[right]):
        check_x = left
        check_y = right
        sum = a_list[left]+a_list[right]

    #처음에 sum으로 했는데 sum이 a_list[left]+a_list[right]값보다 0에 가까우면 
    #같은 부분만 인덱스가 변하므로 적절하지 않았음
    if  a_list[left]+a_list[right] > 0:
        right -= 1
    elif a_list[left]+a_list[right] < 0:
        left += 1
    
print(a_list[check_x]+a_list[check_y])

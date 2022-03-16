N = int(input())
numbers = list()
for i in range(0, N, 1):
    number = int(input())
    numbers.append(number)
count = 0
while 1:
    max_value = max(numbers)
    if numbers.index(max_value) == 0:
        break
    else: #최댓값을 찾아서 표를 하나씩 매수
        max_index = numbers.index(max_value)
        numbers[max_index] -= 1
        numbers[0] += 1
        count += 1
for i in range(1, N, 1): #최댓값이 중복일 경우 그 중 하나만 매수
    if numbers[0] == numbers[i]:
        count += 1
        break
print(count)
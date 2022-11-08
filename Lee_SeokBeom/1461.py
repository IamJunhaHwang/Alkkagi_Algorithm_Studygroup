import sys

input = sys.stdin.readline

n, m = map(int, input().split())

book_list = list(map(int, input().split()))

result = 0
book_list.sort()
left = []
right = []
for i in book_list:
    if i < 0:
        left.append(abs(i))
    else:
        right.append(i)

left.sort(reverse=True)
right.sort(reverse=True)
dir_list = []
for i in range(0, len(left), m):
    dir_list.append(left[i])

for i in range(0, len(right), m):
    dir_list.append(right[i])

dir_list.sort(reverse=True)

for i in dir_list:
    result += i * 2

result -= max(dir_list)

print(result)


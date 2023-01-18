import sys
INF = int(1e9)

input = sys.stdin.readline

#최대 10만 이므로 n^2은 쓸수 없음
n, s = map(int, input().split())

numList = list(map(int, input().split()))


result = 0

length = INF
intervalSum = 0
end = 0

#투포인터 예시참조
#https://stonetiger0912.github.io/algorithm/Algorithm-etc/#%ED%88%AC-%ED%8F%AC%EC%9D%B8%ED%84%B0
for start in range(n):
    while intervalSum < s and end < n:
        intervalSum += numList[end]
        end += 1
    if intervalSum >= s:
        length = min(length, end-start)
        intervalSum -= numList[start]

if length == INF:
    print(0)
else:
    print(length)
def dp_stair(n, A):
    if n == 1:
        return A[0]
    elif n == 2:
        return A[0] + A[1]
    elif n == 3:
        x = A[0] + A[2]
        y = A[1] + A[2]
        return x if x > y else y
    else:
        x = A[n-1] + A[n-2] + dp_stair(n-3, A)
        y = A[n-1] + dp_stair(n-2, A)
        return x if x > y else y

N = int(input())
stairs = list()
for i in range(0, N, 1):
    num = int(input())
    stairs.append(num)
print(dp_stair(N, stairs)) #boj결과 시간초과
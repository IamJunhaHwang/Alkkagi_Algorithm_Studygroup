from sys import stdin, exit
n,s =   map(int, stdin.readline().split())
arr = list(map(int,stdin.readline().split()))

plus = [0] # 요소를 차례로 더한 리스트. ex) [1,1,1,1] -> [0,1,2,3,4]
for i in range(len(arr)):
    plus.append(plus[-1] + arr[i])

#부분합의 길이를 늘려가면서 s보다 큰 부분합을 찾음.
for i in range(1,n+1):      # 부분합의 길이 1~n
    for j in range(n-i+1):  
        if plus[j+i]-plus[j]>=s:    # 부분합이 s이상이면 현재 길이 출력
            exit(print(i))
            
print(0)    # s보다 큰 부분합이 없다.




# 파이파이로만 성공하는거 보니까 원래 n^2이 나오면 안되는?듯
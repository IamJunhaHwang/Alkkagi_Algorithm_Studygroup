N = int(input())
stairs = [0 for i in range(301)]
dp_table = [0 for i in range(301)]
for i in range(0, N, 1):
    num = int(input())
    stairs.append(num)

dp_table[0] = stairs[0]
dp_table[1] = stairs[0] + stairs[1]
dp_table[2] = max(stairs[0]+stairs[2], stairs[1]+stairs[2])
for i in range(3, N, 1):
    dp_table[i] = max(stairs[i]+stairs[i-1]+dp_table[i-3], 
    stairs[i]+dp_table[i-2])
print(dp_table[N-1])
import sys
from itertools import combinations

input = sys.stdin.readline

def dfs(depth):
    global result
    if depth == 15:
        result = 1
        for i in scores:
            if i.count(0) != 3:
                result = 0
                break
        return
    
    a, b = num_cases[depth]
    for x, y in ([0, 2], [1, 1], [2, 0]):
        if scores[a][x] > 0 and scores[b][y] > 0:
            scores[a][x] -= 1
            scores[b][y] -= 1
            dfs(depth+1)
            scores[a][x] += 1
            scores[b][y] += 1


num_cases = list(combinations(range(6), 2))
answer = []
for _ in range(4):
    input_list = list(map(int, input().split()))
    scores = [input_list[i:i+3] for i in range(0, 16, 3)]
    result = 0
    dfs(0)
    answer.append(result)

print(*answer)
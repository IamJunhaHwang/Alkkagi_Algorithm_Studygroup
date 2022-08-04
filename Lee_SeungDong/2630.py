N = int(input())

paper = [[0 for i in range(N)] for j in range(N)]
for i in range(N):
    temp = input()
    for j in range(N):
        paper[i][j] = int(temp.split()[j])

def canP(x1, y1, x2, y2):
    if x1==x2 and y1==y2:
        return True
    for i in range(x1, x2+1):
        for j in range(y1, y2+1):
            if paper[i][j]==paper[x1][y1]:
                continue
            else:
                return False
    return True

blue = 0
white = 0

def checkP(x1, y1, x2, y2):
    global blue, white, paper
    if canP(x1, y1, x2, y2):
        if paper[x1][y1]==1:
            blue += 1
        else:
            white += 1
    else:
        dx = x2-x1
        dy = y2-y1
        checkP(x1, y1, x1+int(dx/2), y1+int(dy/2))
        checkP(x1, y2-int(dy/2), x1+int(dx/2), y2)
        checkP(x2-int(dx/2), y1, x2, y1+int(dy/2))
        checkP(x2-int(dx/2), y2-int(dy/2), x2, y2)

checkP(0, 0, N-1, N-1)
print(white)
print(blue)
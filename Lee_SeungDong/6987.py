#대진표
home = (0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4)
away = (1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5)

#점수판(기록용, 체크용)
score_table = [[0, 0, 0] for i in range(6)]
check_table = [[[0, 0, 0] for i in range(6)] for i in range(4)]

#출력할 값
res = [0, 0, 0, 0]

#dfs 재귀함수
def dfs(test, game):
    #다 확인했는데 일치하면 1 아니면 0인 상태로 return
    if game==15:
        for i in range(6):
            for j in range(3):
                if score_table[i][j]!=check_table[test][i][j]:
                    return
        res[test] = 1
        return

    #대진표를 보고 game번 째에 어느 팀이 붙는지 확인
    home_team = home[game]
    away_team = away[game]

    #home팀 기준으로 이긴 경우, 비긴 경우, 진 경우를 다 해보면서 15게임을 채우고
    #score와 check가 일치하면 종료하고 아니면 돌아가서 다음 경우를 확인
    #home win, away lose
    score_table[home_team][0] += 1
    score_table[away_team][2] += 1
   # print(score_table)
    dfs(test, game+1)
    #print(score_table)
    score_table[home_team][0] -= 1
    score_table[away_team][2] -= 1

    #home, away draw
    score_table[home_team][1] += 1
    score_table[away_team][1] += 1
    dfs(test, game+1)
    score_table[home_team][1] -= 1
    score_table[away_team][1] -= 1

    #home lose, away win
    score_table[home_team][2] += 1
    score_table[away_team][0] += 1
    dfs(test, game+1)
    score_table[home_team][2] -= 1
    score_table[away_team][0] -= 1

#4번 반복
for T in range(4):
    #입력받기
    input_string = input()
    for i in range(6):
        for j in range(3):
            check_table[T][i][j] = int(input_string.split()[i*3+j])
    
for T in range(4):
    #완전탐색 시작
    dfs(T, 0)

for T in range(4):
    print(res[T], end=' ')
    
num = int(input())

global star_list 
star_list = [['*'] * num for _ in range(num)]

def recur(star_list, num, x, y):
    num = num // 3
    if num == 0:
        return

        
    for j in range(y+num, y+num*2):
        for i in range(x+num, x+num*2):
            star_list[j][i] = ' '

    for j in range(y, y+num*3, num):
        for i in range(x, x+num*3, num):
            if j == num and i == num:
                continue
            else:
                recur(star_list, num, i, j)



recur(star_list, num, 0, 0)

for i in range(num):
    for j in range(num):
        print(star_list[i][j],end='')
    print()
    
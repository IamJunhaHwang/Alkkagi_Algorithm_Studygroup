from shlex import join


def comb(lst, n):
    combination = []
    if n > len(lst):
        return combination
    
    if n == 1:
        for i in lst:
            combination.append([i])
    elif n > 1:
        for i in range(len(lst)-n+1):
            for j in comb(lst[i+1:], n-1):
                combination.append([lst[i]]+j)

    return combination

L, C = map(int, input().split())
C_letter = input()

vowel = ['a', 'e', 'i', 'o', 'u']
vow = []
con = []
result = []

for i in range(C):
    letter = C_letter.split()[i]
    if letter in vowel:
        vow.append(letter)
    else:
        con.append(letter)

for i in range(L-2):
    if i > len(vow)-1:
        break
    
    pwls = []
    for k in comb(vow, i+1):
        for j in comb(con, L-i-1):
            pw = k+j
            pwls.append(sorted(pw))

    result = result + pwls

result.sort()
for i in range(len(result)):
    prtstr = ''
    for j in range(len(result[i])):
        prtstr = prtstr + result[i][j]
    print(prtstr)
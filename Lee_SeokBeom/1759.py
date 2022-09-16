from itertools import combinations

l, c = map(int, input().split())

alphabet_lst = list(input().split())
alphabet_lst.sort()

vow = ['a', 'e', 'i', 'o', 'u']

per_list = combinations(alphabet_lst, l)


for arr in per_list:
    lst = list(arr)
    count = 0
    for i in lst:
        if i in vow:
            count += 1

    if count >= 1 and (l - count) >= 2:
            print(''.join(lst))

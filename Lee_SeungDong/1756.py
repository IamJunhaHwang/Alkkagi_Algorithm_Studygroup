def slice_oven(oven):
    for i in range(1, len(oven)):
        if oven[i] > oven[i-1]:
            oven[i] = oven[i-1]

def stack_pizza(oven, pizza):
    z = 0
    for o in range(len(oven)-1, 0, -1):
        if z >= len(pizza):
            break
        if pizza[z] <= oven[o]:
            res = o + 1
            z += 1
    if z < len(pizza):
        res = 0
    return res

D, N = map(int, input().split())

oven_stack = list(map(int, input().split()))
slice_oven(oven_stack) #오븐을 깔때기 모양으로 바꾸기
pizza_size = list(map(int, input().split()))

print(stack_pizza(oven_stack, pizza_size))
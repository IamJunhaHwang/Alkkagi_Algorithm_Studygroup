pipe = input()
dupli = 0
result = 0
lazer = False
stack = []

for i in range(len(pipe)-1):
    dupli = len(stack)
    if pipe[i]=='(':
        if pipe[i+1]==')':
            result += dupli
            lazer = True
        else:
            stack.append('(')
    else:
        if lazer:
            lazer = False
            continue
        else:
            result += 1
            stack.pop()

print(result+1)
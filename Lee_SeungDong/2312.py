N = int(input())
for i in range(0, N, 1):
    num = int(input())
    prime = 2
    while 1:
        count = 0
        while num%prime == 0:
            num = num/prime
            count += 1
        if count != 0:
            print('{0} {1}'.format(prime, count))
        prime += 1
        if prime > num:
            break
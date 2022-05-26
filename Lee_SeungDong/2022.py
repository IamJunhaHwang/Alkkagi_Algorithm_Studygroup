import math

x, y, c = map(float, input().split())
left = 0.0
right = min(x, y)

while right-left >= 0.001: #오차를 고려한 종료조건
    d = (right+left) / 2.0
    hx = math.sqrt(x**2 - d**2)
    hy = math.sqrt(y**2 - d**2)
    hc = hx*hy / (hx+hy)
    
    if c > hc: #이분탐색
        right = (right+left) / 2.0
    else:
        left = (right+left) / 2.0
        
print("{0:.3f}".format(right))
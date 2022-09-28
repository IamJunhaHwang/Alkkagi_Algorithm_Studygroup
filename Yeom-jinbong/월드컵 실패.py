case1=list(input().split())
case2=list(input().split())
case3=list(input().split())
case4=list(input().split())
wc=[]
sol=[]
wc.append(case1)
wc.append(case2)
wc.append(case3)
wc.append(case4)
for case in wc:
  count=0
  a=[]
  b=[]
  c=[]
  d=[]
  e=[]
  f=[]
  for i in case:
   if count<4:
     a.append(i)
   if count>=3 and count<6:
     b.append(i)
   if count>=6 and count<9:
     c.append(i)
   if count>=9 and count<12:
     d.append(i)
   if count>=12 and count<15:
     e.append(i)
   if count>=15:
     f.append(i)
   count +=1
  win=int(a[0])+int(b[0])+int(c[0])+int(d[0])+int(e[0])+int(f[0])
  lose=int(a[2])+int(b[2])+int(c[2])+int(d[2])+int(e[2])+int(f[2])
  A=int(a[0])+int(a[1])+int(a[2])
  B=int(b[0])+int(b[1])+int(b[2])
  C=int(c[0])+int(c[1])+int(c[2])
  D=int(d[0])+int(d[1])+int(d[2])
  E=int(e[0])+int(e[1])+int(e[2])
  F=int(f[0])+int(f[1])+int(f[2])
  draw=a[1]+b[1]+c[1]+d[1]+e[1]+f[1]
  draw=list(draw)
  count2=0
  for i in draw:
    if i!='0':
      count2+=1
  if win==lose:
    if A==5 and B==5 and C==5 and D==5 and E==5 and F==5:
      if count2==0 or count2==2 or count2==4 or count==6:
        if (A+B+C+D+E+F)==30:
          sol.append(1)
        else:
          sol.append(0)
      else:
        sol.append(0)
    else:
      sol.append(0)
  else:
    sol.append(0)
  count=0
print(sol[0],sol[1],sol[2],sol[3])

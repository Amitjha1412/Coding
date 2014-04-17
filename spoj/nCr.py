import math
def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
for i in range(3,21):
    e=0
    o=0
    for j in range(i+1):
        if(nCr(i,j)%2==0):
            e+=1
        else:
            o+=1
    print i,e,o

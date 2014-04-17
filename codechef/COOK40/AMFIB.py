t=raw_input()
t=int(t)
import math
def is_square(apositiveint):
    x = apositiveint // 2
    seen = set([x])
    while x * x != apositiveint:
        x = (x + (apositiveint // x)) // 2
        if x in seen:
            return False
        seen.add(x)
    return True
fib=[]
while(t>0):
    a=raw_input()
    a=int(a)
    n=a*a
    n=n*5
    x=n+4
    y=n-4
    if(a not in fib):
        if(is_square(x) or is_square(y)):
            print "YES"
            fib.append(a)
        else:
            print "NO"
    else :
        print "YES"
    t=t-1

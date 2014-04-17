import random
i=100
print 100
print
while(i>0):
    a=random.randint(1,10000)
    b=random.randint(1,a)
    print a,b
    print
    while(a>0):
        print random.randint(0,2000000000),
        a=a-1
    print
    print
    i=i-1

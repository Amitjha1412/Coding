import random
n=random.randint(1,10)
print n
for i in range(n):
    for j in range (n):
        a=random.randint(1,10)
        print a,
    print
q=random.randint(1,100000)
print q
for i in range(q):
    x1=random.randint(1,n)
    y1=random.randint(1,n)
    x2=random.randint(x1,n)
    y2=random.randint(y1,n)
    print x1,y1,x2,y2

import random
n=1000000
q=50000
print n,q
for i in range(n):
    print random.randint(1000,2000),
print
for i in range(q):
    a=random.randint(0,2);
    if(a==0):
        print "G",random.randint(0,n),random.randint(0,2000)
    if(a==1):
        print "T",random.randint(0,n),random.randint(0,2000)
    if(a==0):
        k=random.randint(0,n)
        print "S",k,random.randint(k,n)

import random
n=random.randint(1,100001);
m=random.randint(1,100001);
print n,m
for i in range(m):
    a=random.randint(1,n+1);
    b=random.randint(a,n+1);
    print a,b

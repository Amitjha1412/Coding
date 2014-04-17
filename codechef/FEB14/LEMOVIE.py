import itertools
b=list()
ans=[0,0,0,0,0,0,0]
for i in range(1,30):
    b.append(i)
#b=[1,2,2,4]
a=list(itertools.permutations([1,2,3,4,5,6], 6))
for i in a:
    m=0
    k=0
    for j in i:
        if(j>m):
            m=j
            k+=1
    ans[k]+=1
print ans

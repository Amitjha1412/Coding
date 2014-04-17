t=input()
while(t>0):
    a=raw_input()
    b=[]
    b=a.split(" ")
    l=int(b[0])
    d=int(b[1])
    s=int(b[2])
    c=int(b[3])
    c=1+c
    d=d-1
    a=1
    t=t-1
    while(d>0):
        if(d%2==1):
            a=a*c
        c=c*c
        d=d/2
        if(a>=l):
            break
    a=a*s
    if(a>=l):
        print "ALIVE AND KICKING"
    else:
        print "DEAD AND ROTTING"

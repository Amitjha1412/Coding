import numpy as np
t=input()
while(t>0):
    t=t-1
    n=input()
    a=raw_input()
    arr=[]
    a=a.split(" ")
    for i in a:
        arr.append(int(i))
    a=raw_input()
    a=a.split(" ")
    A=int(a[0])
    B=int(a[1])
    C=int(a[2])
    #for i in range(0,n):
     #   arr[i]=arr[i]%C
    arr=np.array(arr)%C
    arr=arr.tolist()
    s=raw_input()
    for i in range(0,len(s)):
        if(s[i]=='A'):
    #        for j in range(i,n):
    #            arr[j]+=A
    #            arr[j]%=C
            arr=np.array(arr)+A
            arr=np.array(arr)%C
            arr=arr.tolist()
        elif(s[i]=='M'):
     #       for j in range(i,n):
     #           arr[j]*=B
     #           arr[j]%=C
            arr=np.array(arr)*B
            arr=np.array(arr)%C
            arr=arr.tolist()
        elif(s[i]=='R'):
            arr[i:n]=reversed(arr[i:n])
        print arr[i],
    print

import sys
t=raw_input()
t=int(t)
def isprime(n):
    '''check if integer n is a prime'''
    # make sure n is a positive integer
    n = abs(int(n))
    # 0 and 1 are not primes
    if n < 2:
        return False
    # 2 is the only even prime number
    if n == 2:
        return True
    # all other even numbers are not primes
    if not n & 1:
        return False
    # range starts with 3 and only needs to go up the squareroot of n
    # for all odd numbers
    for x in range(3, int(n**0.5)+1, 2):
        if n % x == 0:
            return False
    return True
def power(a,b,c):
    ret=1
    while(b>0):
        if(b%2==1):
            ret*=a
        a=a*a
        b=b/2
    return ret
def modpower(a,b,c):
    ret=1
    while(b>0):
        if(b%2==1):
            ret*=a
            ret=ret%c
            if(ret<0):
                ret+=c
        a=a*a
        a=a%c
        if(a<0):
            a+=c
        b=b/2
    return ret
while(t>0):
    t-=1
    n1,k1,n2,k2,n = map(int,sys.stdin.readline().split())
    p1=modpower(n1,k1,n)
    if(isprime(n)):
        p2=modpower(n2,k2,n-1)
    else:
        p2=power(n2,k2,n)
    p=modpower(p1,p2,n)
    p=p%n
    if(p<0):
        p+=n
    print p

import psyco
psyco.full()
import sys
import fractions
q=[]
h=[]
def build(s):
    p=137
    q.append(1);
    h.append(0);
    for i in s:
        q.append(p*q[-1])
        h.append(p*h[-1]+ord(i))
def hash(L,R):
        return (h[R]-q[R-L]*h[L])
def Palindromes(seq):
    build(seq)
    seqLen = len(seq)
    l = []
    i = 0
    palLen = 0
    while i < seqLen:
        if i > palLen and seq[i - palLen - 1] == seq[i]:
            palLen += 2
            i += 1
            continue
        l.append(palLen)
        s = len(l) - 2
        e = s - palLen
        for j in xrange(s, e,-1):
            d = j - e - 1
            if l[j] == d:
                palLen = d
                break
            l.append(min(d, l[j]))
        else:
            palLen = 1
            i += 1
    l.append(palLen)
    lLen = len(l)
    s = lLen - 2
    e = s - (2 * seqLen + 1 - lLen)
    for i in xrange(s, e, -1):
        d = i - e - 1
        l.append(min(d, l[i]))
    sub=set()
    for i in xrange(1,len(l)):
        x=l[i]
        while(x>0):
            j=i-x
            j=j/2
            sub.add(hash(j,j+x))
            x=x-2
    return len(sub)
t=sys.stdin.readline()
k=int(sys.stdin.readline())
n=Palindromes(t[:-1])
print n
ans=0
for i in xrange(1,k+1):
    ans+=n**(fractions.gcd(k,i))
if(k%2==0):
    x=k/2
    e=n**x
    ans+=x*e*(n+1)
else :
    e=(k+1)/2
    ans+=k*(n**e)
ans=ans/(2*k)
print ans

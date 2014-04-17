def gen_primes():
    D = {}
    q = 2
    while True:
        if q not in D:
            yield q
            D[q * q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1

n=1;
s=''
for i in gen_primes():
    s=s+str(i)+','
    if(n==1000000):
        break
    n+=1
print s

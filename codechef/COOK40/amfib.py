def fibGenerator():
    a, b = 0, 1
    yield 0
    while True:
        a, b = b, a + b
        yield a

limit=10**1000
fibonaccinumbers = []
fib = fibGenerator()
while(1):
    a=next(fib)
    if(a>limit):
        break;
    fibonaccinumbers.append(a)
t=raw_input()
t=int(t)
while(t>0):
    n=raw_input()
    n=int(n)
    if n in fibonaccinumbers:
        print "YES"
    else:
        print "NO"
    t=t-1

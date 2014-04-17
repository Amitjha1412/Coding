import random
import string
def randomword(length):
   return ''.join(random.choice(string.lowercase) for i in range(length))
a=randomword(50000)
print a+a[::-1]
print 600

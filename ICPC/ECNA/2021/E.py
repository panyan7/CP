import math
import sys

for i in sys.stdin:
    arr = i.split()
    m = int(arr[0])
    n = int(arr[1])
    p = int(arr[2])
    break


def choose(a, b):
    if (a < b or b < 0 or a < 0):
        return 0
    return math.factorial(a) // math.factorial(b) // math.factorial(a-b)

def perm(a, b):
    if (a < b or b < 0 or a < 0):
        return 0
    return math.factorial(a) // math.factorial(a-b)

v = 0

for i in range(max(0, p+n-m), min(n, p-n+1)):
    f = choose(n-1, i) * pow(2, n-i-1) * math.factorial(n-1+i) * choose(p-1, n-1+i) * perm(m-2*n, p-n-i)
    v += 2 * n * f

d = perm(m, p)

d = int(d)
v = int(v)
fact = math.gcd(v, d)
d //= fact
v //= fact
# print(int(v),"/",int(d))
if n == 0 and p == 0:
    print("1/1")
else:
    print(str(int(v)) + "/" + str(int(d)))




tt = int(input())
for _ in range(tt):
    n = int(input())
    k = int(input())
    a = [0 for i in range(n)]
    for i in range(len(a)):
        a[i] = int(input())
    k += 1
    res = 0
    for i in range(1, n):
        res += (pow(10, a[i]-a[i-1])-1)*pow(10, a[i-1])
        k -= min(k, pow(10, a[i]-a[i-1])-1)
        if k <= 0:
            break
    res += k * pow(10, a[-1])
    print(res)

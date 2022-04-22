import sys
input = sys.stdin.readline

def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))

def solve():
    rc = input().strip('\n').split()
    r = int(rc[0])
    c = int(rc[1])
    res = []
    for i in range(r*2+1):
        if i % 2 == 0:
            res.append('+-' * c + '+')
        else:
            res.append('|.' * c + '|')
    res[0] = '..' + res[0][2:]
    res[1] = '.' + res[1][1:]
    for line in res:
        print(line)

if __name__ == "__main__":
    tt = 1
    tt = inp()
    for _ in range(tt):
        print(f'Case #{_+1}:')
        solve()

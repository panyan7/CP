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
    pass

if __name__ == "__main__":
    tt = 1
    tt = inp()
    for _ in range(tt):
        solve()

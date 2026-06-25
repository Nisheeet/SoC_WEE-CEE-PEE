import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')
# yn = lambda condition: print("YES" if condition else "NO")

for qwertyuiop in range(int(input())):
    a,b = input().split()
    m = min(len(a),len(b))
    i = 0
    ans = 0
    d = int(b[:len(b)-m+i+1])-int(a[:len(a)-m+i+1])
    while(d <= 1 and i<m):
        if(d == 0): ans += 2
        else: ans += 1
        i += 1
        if(i == m): break
        d = int(b[:len(b)-m+i+1])-int(a[:len(a)-m+i+1])
    print(ans)
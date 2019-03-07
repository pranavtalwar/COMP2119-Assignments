def f2(n):
    if (n<=2):
        return 1
    else:
        p = 1
        q = 1
        for i in range(3,n+1):
            r = p+q
            p=q
            q=r
    return r;


def read_integers(filename):
    with open(filename) as f:
        return [int(x) for x in f]
    
file2 = open('output2.txt', 'w+')
intlist = read_integers('input2.txt')


for integer in intlist:
    ans = f2(integer)
    file2.write(str(ans) + '\n')

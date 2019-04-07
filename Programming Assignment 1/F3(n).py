import numpy as np
G = np.array([[0,1],[1,1]])

def PowerofG(n):
    if(n==1):
        return G
    else:
        if(n%2==0):
            H = PowerofG(n/2)
            return np.matmul(H,H)
        else:
            H = PowerofG((n-1)/2)
            return np.matmul(np.matmul(H,H), G)


def f3(n):
    temp = PowerofG(n)
    return temp[0][1]




def read_integers(filename):
    with open(filename) as f:
        return [int(x) for x in f]
    

file2 = open('output3.txt', 'w+')
intlist = read_integers('input3.txt')

for integer in intlist:
    ans = f3(integer)
    file2.write(str(ans) + '\n')

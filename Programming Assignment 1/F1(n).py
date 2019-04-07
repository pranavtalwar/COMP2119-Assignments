def f1(n):
    if(n<=2):
        return 1
    else:
        return (f1(n-1) + f1(n-2))
  
def read_integers(filename):
    with open(filename) as f:
        return [int(x) for x in f]
    

file2 = open('output1.txt', 'w+')

intlist = read_integers('input1.txt')

for integer in intlist:
    ans = f1(integer)
    file2.write(str(ans) + '\n')




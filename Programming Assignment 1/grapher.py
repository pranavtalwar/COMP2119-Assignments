import matplotlib.pyplot as plt
import numpy as np
import time

def f1(n):
    if(n<=2):
        return 1
    else:
        return (f1(n-1) + f1(n-2))
    
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

def caltime(method):
    inputsize = []
    for i in range(1,30):
        inputsize.append(i)
    calctime = []
    for input in inputsize:
        curr_time = time.time()
        ans = method(input)
        end_time = time.time()
        calctime.append(end_time - curr_time)
    plt.plot(inputsize, calctime)
    plt.plot()
    plt.title('f1 runtime')
    plt.gca().legend(('f1'))
    plt.xlabel('Input Size')
    plt.ylabel('Runtime')
    plt.show()

def caltime2(method, method2):
    inputsize = []
    inputsize2 = []
    calctime = []
    calctime2 = []
    for i in range(1,2000):
        inputsize.append(i)
    for input in inputsize:
        curr_time = time.time()
        ans = method(input)
        end_time = time.time()
        calctime.append(end_time - curr_time)
    for i in range(1,2000):
        inputsize2.append(i)
    for input in inputsize:
        curr_time = time.time()
        ans = method2(input)
        end_time = time.time()
        calctime2.append(end_time - curr_time)
    plt.plot(inputsize, calctime)
    plt.plot(inputsize2, calctime2)
    plt.title('Comparing f2 and f3 runtime')
    plt.gca().legend(('f2','f3'))
    plt.xlabel('Input Size')
    plt.ylabel('Runtime')
    plt.plot()


caltime(f1)
caltime2(f2,f3)








    
    
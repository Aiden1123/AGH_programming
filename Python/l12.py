class arithmeticSequence:
    
    def __init__(self,a,r,count):
        self.a = a
        self.r = r
        self.count = count

    def __iter__(self):
        self.i=0
        return self

    def __next__(self):
        
        if self.i==self.count:
            raise StopIteration

        self.i += 1
        return self.a + self.r * (self.i-1)

class arithmeticSequence2:
    
    def __init__(self,a,r,max):
        self.a = a
        self.r = r
        self.max = max

    def __iter__(self):
        self.last = None
        return self

    def __next__(self):
        
        if self.last == None:
            self.curr = self.a
        else:
            self.curr += self.r

        if self.curr>=self.max:
            raise StopIteration
        self.last = self.curr
        return self.curr

for word in arithmeticSequence(0,3,5):
    print(word)

for word in arithmeticSequence2(0,3,13):
    print(word)


#2

class myRand:
    def __init__(self,count):
        self.a = 44485709377909
        self.x = 1
        self.m = 2**48
        self.count = count

    def __iter__(self):
        self.i = 0
        return self

    def __next__(self):
        if self.i==self.count:
            raise StopIteration
        
        self.x = (self.a * self.x) % self.m
        self.i+=1
        return self.x

def fun(x):
    return -(x-3)**2 + 1

#Recatangle (2,0) x (4,1)
#Integration Limits: 2 and 4

n = 10000
t = 1

iter = myRand(n*2)

for rnd in iter:
    x = ((rnd % 2001) / 1000) +2
    y = (next(iter) % 1001) /1000

    if y > 0 and y <= fun(x):
        t+=1
    elif y < 0 and y >= fun(x):
        t-=1


print("Integral is approximately equal: ", 2*t/n)

#3

import scipy.misc
import math

class NewtonRaphson:

    def __init__(self,f,x,eps):
        self.f = f
        self.x = x
        self.eps = eps

    def __iter__(self):
        return self

    def __next__(self):
        diff = self.x - self.f(self.x) / scipy.misc.derivative(self.f, self.x)
        
        if abs(diff-self.x) >= self.eps:
            self.x = diff
            return diff
        
        raise StopIteration


def fun(x):
    return math.sin(x) - (0.5 * x)**2


for approx in NewtonRaphson(fun,1.5,1e-5):
    print(approx)
import abc

def myRange(start,end = None,step = 1):         #from generator labs
    
    if end == None:
        end = start
        start = 0
    
    i = start

    if step < 0:
        while i > end:
            yield i
            i+=step
        return 

    while i < end:
        yield i
        i+=step
    return

class Calka(abc.ABC):

    def __init__(self,lower,upper,steps,fun):
        self.lower = lower
        self.upper = upper
        self.steps = steps
        self.fun = fun

    @abc.abstractmethod
    def calculate(self):
        pass


class Trapeze(Calka):

    def calculate(self):
        h = (self.upper - self.lower) / self.steps
        
        s = 0
        arr = list(myRange(self.lower,self.upper,h))
        for i in range(len(arr)-1):
            s += self.fun( arr[i] + arr[i+1])

        return s*h/2

class Simpson(Calka):

    def calculate(self):
        h = (self.upper - self.lower) / (self.steps * 2)
    
        odd = 0
        for y in list(myRange(self.lower,self.upper,h))[1:2*self.steps:2]:
            odd += self.fun(y)

        even = 0
        for y in list(myRange(self.lower,self.upper,h))[2:2*self.steps:2]:
            even += self.fun(y)

        return (h/3) * (self.fun(self.lower) + 4 * odd + 2 * even + self.fun(self.upper))

def f(x):
    return 4*x

print(Simpson(0,2,1000,f).calculate())
print(Trapeze(0,2,1000,f).calculate())

#2

class Stack:

    def __init__(self,stack = None):
        if isinstance(stack,Stack):
            self.arr = stack.arr.deepcopy()
        else:
            self.arr = []
    
    def add(self,x):
        self.arr.append(x)

    def pop(self):
        return self.arr.pop()

    def extend(self,stack):
        self.arr.extend(stack.arr.deepcopy())

    def size(self):
        return len(self.arr)

    def print(self):
        print(self.arr)


class SortedStack(Stack):
    
    def add(self,x):
        if len(self.arr) == 0:
            self.arr.append(x)
        elif len(self.arr) == 1 and self.arr[0] != x:
            self.arr.append(x)    
        elif len(self.arr) >= 2:
            if self.arr[0] < self.arr[len(self.arr)-1] and self.arr[len(self.arr)-1] < x:
                self.arr.append(x)
            elif self.arr[0] > self.arr[len(self.arr)-1] and self.arr[len(self.arr)-1] > x:
                self.arr.append(x)
            
import random

sum = 0

for _ in range(100):
    stack = SortedStack()

    for x in random.choices(list(range(1,101)),k=100):
        stack.add(x)

    sum+=stack.size()

print("average:",sum/100)

#3
import os

class Counter:

    def __init__(self,filename):
        self.filename = filename

    def count(self):
        
        with open(self.filename) as file:
             wc = len(file.read().replace("\n"," ").split(" "))

        with open(self.filename) as file:
             lines = len(file.readlines())

        return wc,lines,os.path.getsize(self.filename)

    @staticmethod
    def filesCount(files):
        sumWc = 0
        sumLines = 0
        sumBytes = 0

        for f in files:
            wc,lines,bytes = Counter(f).count()
            sumWc+=wc
            sumLines+=lines
            sumBytes+=bytes
            print(wc,lines,bytes,f)

        if len(files) > 1:
            print(sumWc,sumLines,sumBytes,"total")


Counter.filesCount(["l3.py","l4.py","l5.py","l8.py"])
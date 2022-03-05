import time
import sys

"""
powt=1000
N=10000


def forStatement(sequence, fun):
    res = []
    for el in sequence:
        res.append(fun(el))
    return res

def listComprehension(sequence, fun):
    return [fun(el) for el in sequence]

def mapFunction(sequence, fun):
    return map(fun,sequence)

def generatorExpression(sequence, fun):
    return (fun(el) for el in sequence)

def tester(fun):
    start = time.time_ns()
    for _ in range(powt):
        
        a = fun(range(N),lambda x: x)
        fun(range(N), lambda x : x**2)

        res = 0
        for x in a:
            res += x

        sum(a)
        
        list(a)

    return time.time_ns() - start



print(sys.version)
test=(forStatement, listComprehension, mapFunction, generatorExpression)
for testFunction in test:
    print(testFunction.__name__.ljust(20), '=>', tester(testFunction))

"""

#2

import random

listA = []
listB = []

for _ in range(100):
    listA.append(random.randrange(20))
    listB.append(random.randrange(20))

res = filter(lambda x:  x[0]+x[1]>3 and x[0]+x[1]<15, [el for el in zip(listA,listB)])

print(*res)

#3

def fitLine(x,y):
    mean = lambda x: sum(x)/len(x)
    xMean = mean(x)
    D = sum([ el for el in map(lambda x : (x - xMean)**2,x)])
    a = sum([el for el in map(lambda x : x[1] * (x[0] - xMean),[el for el in zip(x,y)])])/D
    b = mean(y) - a * mean(x)

    return D,a,b

fitLine([12,3432,2],[1243,432,3])

#4

def myreduce(fun, seq):

    res = fun(seq[0],seq[1])


    print(res)

    for el in seq[2:]:
        res = fun(res,el)

    return res

print(myreduce(lambda x,y: x*y,[1,2,3,4,5]))
print(myreduce(lambda x,y: x+y,[10,20,30,40,50]))

#5

data = [[2,3],[4,5],[6,7],[8,9],[10,11]]

print(myreduce(lambda arr,num: [arr[0].append(num[0]),arr[1].append(num[1]),arr[0],arr[1]][2:] , [ [ [] , [] ] , *data]))
print([[el for el in map(lambda x : x[0], data)] , [el for el in map(lambda x : x[1], data)]])

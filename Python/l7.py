def pascal():
    res = []

    while True:
        res.append(1)
        #print(list(range(len(res)))[::-1][1:-1])

        for i in list(range(len(res)))[::-1][1:-1]:
            #print(res[i] + res[i-1])
            res[i] = res[i] + res[i-1]

        yield res, sum(res)

p = pascal()
for _ in range(10):
    print(next(p))

#2

import random

def zeroOnes(N):
    return [random.randint(0,1) for _ in range(N)]

def distance(zerosOnes):
    if 1 in zerosOnes:
        x = zerosOnes.index(1)
    
        while 1 in zerosOnes[x+1:]:
            yield zerosOnes.index(1,x+1) - x - 1
            x = zerosOnes.index(1,x+1)
    return

s = zeroOnes(25)
g = distance(s)
print(s)

i = 0
res = 0
for el in g:
        res += el
        i += 1

print(res/i)

#3

def fibonacci():
    arr = [1,0]
    while True:
        arr.append(sum(arr))
        del arr[0]
        yield arr[1]

f = fibonacci()

for _ in range(10):
    print(next(f))

def even(seq):
    for x in seq:
        if x%2 == 0:
            yield x
    return

g = even(list(range(10)))

for el in g:
    print(el)

def until(seq,max):
    for x in seq:
        if x > max:
            return
        yield x
    return

f = fibonacci()

#It is extremely wierd but it works

res = 0
for el in f:
    arr = [el]

    for x in even(arr):
        break
    else:
        continue

    for x in until(arr,100):
        res+= x
        break
    else:
        break

print(res)

#4

def range(start,end = None,step = 1):
    
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

ranges = [range(7), range(-7), range(2,7), range(7,2), range(2,7,2), range(2,7,-2), range(7,2,2), range(7,2,-2)]

for rng in ranges:
    for x in rng:
        print(x,end=" ")
    print()

#5

def u():

    yield 0

    a = 0.05
    i = 0
    u = 0
    x0 = 1
    x = x0

    while x!=1.5:
        yield u + a/x
        u = u + a/x
        print(u)
        i+=1
        x = x0 + i*a


import math

def logarithm(x):
    for z in u():
        est = z
    yield x,est,math.log(x)

print(next(logarithm(1.5)))

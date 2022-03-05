import random

def calculateString(expression):
    transDict = {}
    for char in expression:
        if char.isalpha():
            transDict[ord(char)] = random.randrange(10) + 48

    if ord('x') in transDict:
        del transDict[ord('x')]
    
    expression = expression.translate(transDict)

    randomList = []
    for _ in range(10):
        randomList.append(random.random())

    return [ (x,eval(expression)) for x in [random.random() for z in range(10)] ]

print(calculateString('a*x**2+b*x+c'))

#2

def common(*iterables):
    
    res = []

    for el in iterables[0]:
        for x in iterables[1:]:
            if el not in x:
                break
        else:
            res.append(el)

    return res

print(common([1,2,3], (1,3,5), [3,2]))
print(common([1,2,3], (1,3,5), [3,2,1]))

#3

def combine(a,b, sameSize = True):
    if sameSize:
        return [(a[i],b[i]) for i in range(len(a))]
    else:
        return [(a[i] if i < len(a) else None, b[i] if i < len(b) else None) for i in range( len(a) if len(a) > len(b) else len(b))]

print( combine([1,2,3],[4,5,6]))
print( combine([1,2,3],[2,3],False))

#4

def change(value, coins = (10,5,2)):
    res = ()
    for coin in coins:
        res += (value//coin,)
        value -= (value//coin) * coin
    return res

print( change(29))
print(change(79, (69,1)))

#5

def stupidSearch(target,min,max,method = 'r'):

    counter = 1

    if method == 'r':
        find = random.randint(min,max)
        while find != target:
            max = max if find < target else max - 1
            min = min if find > target else min + 1
            find = random.randint(min,max)
            counter += 1
        print(counter)
    
    else:
        find = (min + max) //2
        while find != target:
            max = max if find < target else max - 1
            min = min if find > target else min + 1    
            find = (min + max) //2
            counter += 1
        print(counter)       
    
stupidSearch(10,0,20)
stupidSearch(69,0,420)
stupidSearch(1,1,2)
stupidSearch(10,0,20,12321)
stupidSearch(69,0,420,(324))
stupidSearch(1,1,3,"agh")
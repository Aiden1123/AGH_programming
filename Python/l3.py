import sys
from statistics import mean

#1
#print(sys.argv)

if len(sys.argv)==1:
    print("Prosze uruchomic program z argumentami!")
else:
    s = ""
    for string in sys.argv[1:]:
        s+=string

    print(s)

    #2
    small = []
    nums = []
    upper = []
    other = []

    for char in s:
        if char.isdigit():
            nums.append(char)
        elif char.islower():
            small.append(char)
        elif char.isupper():
            upper.append(char)
        else:
            other.append(char)

    print(small)
    print(upper)
    print(nums)
    print(other)

    #3
    uniqueSmall = []
    for char in small:
        if char not in uniqueSmall:
            uniqueSmall.append(char)

    print(uniqueSmall)

    smallTuples = [(v,small.count(v)) for v in uniqueSmall]

    #4
    smallTuples.sort(key = lambda x : x[1], reverse=True)
    print(smallTuples)

    #5

    vowels = ['e','y','u','i','o','a']
    consonants = ['q','w','r','t','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m']

    vowelCount = 0
    consonantCount = 0

    for char in s:
        if char in vowels:
            vowelCount += 1
        elif char in consonants:
            consonantCount += 1
    
    linearFunction = [(int(x) , vowelCount * int(x) + consonantCount) for x in nums]

    print(linearFunction)

#6 

y = [23,453,2134,546,231,43]
x = [23,364,2345,213,100,10]

D = 0
for num in x:
    D += (num - mean(x))**2

a = 0
for i in range(len(x)):
    a += y[i]*(x[i] - mean(x))
a/= D

b = mean(y) - a * mean(x)
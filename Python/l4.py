import random

k = 10

randomList = []
for i in range(k):
    randomList.append(random.randrange(5*k))

print(randomList)

pre = {}

for i in range(k):
    pre[i] = id(randomList[i])

for x in range(100):
    random.shuffle(randomList)

post = {}

for i in range(k):
    post[i] = id(randomList[i])

res = {}
res['same'] = 0
res['diff'] = 0

for i in pre:
    if pre[i] == post[i]:
        res['same'] += 1
    else:
        res['diff'] += 1

print(res)

#2

s = ""

for x in range(k):
    s += chr(random.randint(97,122))
    s += "."

s = s[:-1]

print(s)

#3

hundred = []

for x in range(100):
    hundred.append(random.randrange(20))

dict_a = {}
dict_b = {}

for i,v in enumerate(hundred):
    dict_a.setdefault(v,[]).append(i)

for v in hundred:
    dict_b.setdefault(v,[]).append(hundred.index(v) if  len(dict_b[v])==0 else hundred.index(v,dict_b[v][len(dict_b[v])-1]+1))

print(dict_a)
print(dict_b)

#4 

thousand = []
for x in range(1000):
    thousand.append(random.randrange(100,1000000))

res = {}
res["pali"] = 0
res["not pali"] = 0

for x in thousand:
    if str(x) == str(x)[::-1]:
        res["pali"] += 1
    else:
        res["not pali"] += 1

print(res)

#5

d1 = {}
d2 = {}

for i,v in enumerate(random.sample(range(1,100),10)):
    d1[i] = v

for i,v in enumerate(random.sample(range(1,100),10)):    
    d2[i] = v

print(d1,d2)

d1 = dict((v,k) for k,v in d1.items())
d2 = dict((v,k) for k,v in d2.items())

print(d1,d2)

d3 = dict((v,[k]) for k,v in d1.items())
for key,value in d2.items():
    d3.setdefault(value,[]).append(key)

print(d3)
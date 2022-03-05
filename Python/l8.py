def firstTask(filename, n):
    with open(filename) as f:
        print(f.readlines()[n:])
        print(f.readlines()[-n:])
        print(f.readlines()[::n])
        print( x.split(" ")[n] for x in f.readlines())
        print([x[n] for x in f.readlines()])


#2

import glob
from matplotlib.pyplot import hist
import numpy

files = []

for name in glob.glob("*"):
    if name.startswith("data") and name.endswith("in"):
        files.append(open(name))

contents = []
for file in files:
    contents.append(file.readlines())

with open("data.out", "w") as output:
    i = 0
    
    while i < len(contents[0]):
    
        vals = []

        for file in contents:
            vals.append(float(file[i]))
    
        output.write(str(i) + "\t" + str(numpy.average(vals)) + "\t" + str(numpy.std(vals)) + "\n")
        i+=1

for file in files:
    file.close()

#3

def makefile(name):
    with open(name + ".py", "w") as file:
        
        code = """
import matplotlib.pyplot as plt
import glob
import numpy

for name in glob.glob("*"):
    if name.startswith("data") and name.endswith("in"):
        y = numpy.loadtxt(name,unpack=True)
        plt.plot(y)
        plt.savefig(name + '.pdf')
        plt.clf()        

data = numpy.loadtxt("data.out",unpack=True)
plt.errorbar(data[0], data[1], marker='*', yerr=data[2])
plt.savefig('res.pdf')
"""
        
        file.write(code)

makefile("dataScience")

#4

years = [x[5:x.find(".")] for x in glob.glob("rank/*")]

names = {}

for year in years:
    with open("rank/" + year + ".txt",encoding="UTF-8") as file:
        for line in file:
            
            if not line.split(" ")[0] in names:
                names[line.split(" ")[0]] = {}
            
            names[line.split(" ")[0]][year] = line.split(" ")[1][:-1]

with open("rank.out","w",encoding="UTF-8") as out:
    out.write("Nazwisko")
    for year in years:
        out.write("\t" + year)
    out.write("\n")

    for name in names:
        out.write(name)
        for anotheryear in years:
            if anotheryear in names[name]:
                out.write("\t" + names[name][anotheryear])
            else:
                out.write("\t-")
        out.write("\n")

    
#5

words = []

with open("zad5A.in") as data:
        for line in data:
            words.extend([x.removesuffix("\n").removeprefix("(").removesuffix(")").removesuffix("!").removesuffix(".").removesuffix("?") for x in line.lower().split(" ")])

with open("zad5B.in") as data:
        for line in data:
            words.extend([x.removesuffix("\n").removeprefix("(").removesuffix(")").removesuffix("!").removesuffix(".").removesuffix("?") for x in line.lower().split(" ")])

histogram = {}

for word in words:
    if len(word) < 1 or  not word[0].isalpha():
        continue
    if word[0] in histogram:
        histogram[word[0]] += 1
    else:
        histogram[word[0]] = 1

histogram = [(k,v) for k,v in histogram.items()]

histogram.sort(key = lambda x: x[0])

for data in histogram:
    print(data[0], data[1])

print("---------------")

histogram.sort(key = lambda x: x[1])

for data in histogram:
    print(data[0], data[1])

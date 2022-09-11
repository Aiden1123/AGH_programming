from matplotlib import pyplot as plt 

text = open("zad1_zrobione.txt")
#print(text.readlines())

lines = text.readlines()
res = []
i = 0

while i < len(lines):

    x1 = lines[i]
    x2 = lines[i+1]

    x1.replace("\n","")
    x2.replace("\n","")

    res.append(float(x1)**2 + float(x2)**2)
    i+=2
    

plt.plot(res)
plt.show()
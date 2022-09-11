from matplotlib import pyplot as plt 

text = open("zad2_dane.txt")

res = []

for x in text.readlines():
    x.replace("\n","")
    if float(x) != 0:
        res.append(float(x))
    

plt.plot(res)
plt.show()
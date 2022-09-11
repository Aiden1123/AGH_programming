import matplotlib.pyplot as plt
import math

a = 1.0
b = 4.0

n = 8
z = []
x = []
ones = []

for k in range(n+1):
    z.append(math.cos(((2.0*k+1)/(2.0*n+2))*3.14159))
    x.append((z[k]*(b-a)+a+b)/2)
    ones.append(1)
    print(x[k])

plt.plot(x,ones,'.')
plt.show()
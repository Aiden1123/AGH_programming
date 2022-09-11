def f(x):
    return x**2

start = 1
end = 3

s = 0
points = 1000
x = start

step = (end-start)/points

for _ in range(points):
    s += step*((f(start) + f(start+step))/2)
    start += step

print(s)
class point:

    @property
    def x(self):
        return self._x
    
    @x.setter
    def x(self,value):
        self._x = value

    @x.getter
    def x(self):
        return self._x

    @property
    def y(self):
        return self._y
    
    @y.setter
    def y(self,value):
        self._y = value

    @y.getter
    def y(self):
        return self._y    

#2

    def checkRange(minX,maxX,minY,maxY):
        def decFun(fun):
            def wrapper(*args):
                if args[0].x > maxX or args[0].x < minX \
                    or args[0].y > maxX or args[0].y < minY \
                    or args[1].x > maxX or args[1].x < minX \
                    or args[1].y > maxY or args[1].y < minY:
                    raise
                return fun(*args)
        return decFun

    @checkRange(0,100,0,100)
    def add(self,point2):
        new = point()
        new.x = self.x + point2.x
        new.y = self.y + point2.y
        return new

    @checkRange(0,100,0,100)
    def sub(self,point2):
        new = point()
        new.x = self.x - point2.x
        new.y = self.y - point2.y
        return new


#3

import math

class callCount:
    count = {}

    def __init__(self,fun):
        self.fun = fun
        callCount.count[fun.__name__] = 0
        

    def __call__(self,*args):
            callCount.count[self.fun.__name__] += 1
            return self.fun(*args)

    @staticmethod
    def showCount():
        print(callCount.count)

class Areas:

    @staticmethod
    @callCount
    def distance(a,b):
        return math.sqrt((a.x - b.x)**2 + (a.y - b.y)**2)

    @staticmethod
    @callCount
    def Heron(a,b,c):
        p = (Areas.distance(a,b) + Areas.distance(b,c) + Areas.distance(c,a)) / 2
        distA = Areas.distance(a,b)
        distB = Areas.distance(b,c)
        distC = Areas.distance(c,a)

        return math.sqrt(p*(p-distA)*(p-distB)*(p-distC))

    @staticmethod
    @callCount
    def Brahmagupta(a,b,c,d):

        distA = Areas.distance(a,b)
        distB = Areas.distance(b,c)
        distC = Areas.distance(c,d)      
        distD = Areas.distance(d,a)
        p = distA * 2

        return math.sqrt((p-distA) * (p-distB) * (p-distC) * (p-distD))

callCount.showCount()

a = point()
a.x = 1
a.y = 1
b = point()
b.x = 3
b.y = 1
c = point()
c.x = 3
c.y = 3
d = point()
d.x = 1
d.y = 3
print(Areas.Brahmagupta(a,b,c,d))
print(Areas.Heron(a,b,d))
callCount.showCount()
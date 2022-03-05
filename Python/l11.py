

class Life:

    def __init__(self,N,square,iterations):
        self.arr = [ [0 for _ in range(N)] for __ in range(N)]
    #    self.size = N

        for i in range(square):
            for j in range(square):
                self.arr[i][j] = 1

        self.iter = iterations

    def eval(self):
        for _ in range(self.iter):

            copy = [x.copy() for x in self.arr]

            for i in range(len(self.arr)):
                for j in range(len(self.arr)):
                    count = 0

                    for k in range(i-1,i+2):
                        for l in range(j-1,j+2):
                            if copy[k if k < len(self.arr) else 0][l if l < len(self.arr) else 0] == 1:
                                count +=1
                    
                    if (count == 3):
                        self.arr[i][j] = 1
                    elif (count == 2 and self.arr[i][j] == 1):
                        pass
                    else:
                        self.arr[i][j] = 0

    def print(self):
        for line in self.arr:
            print("".join([str(x) for x in line]))


gameOfLife = Life(30,10,5)
gameOfLife.eval()
gameOfLife.print()
print()
gameOfLife = Life(30,11,2)
gameOfLife.eval()
gameOfLife.print()


#2

class Tablica:

    def __init__(self,dim,*vals):
        for val in vals:
            temp = val
            for x in range(0,dim-1):
                temp = temp[0]

        self.arr = []
        self.dim = dim

        for val in vals:
            self.arr.append(val)

    def print(self):
        print(self.arr)

    def getDim(self):
        return self.dim

    def __getitem__(self,key):
        return self.arr[key]

    def __setitem__(self,key,value):
        temp = value
        for x in range(0,self.dim-1):
            temp = temp[0]

        self.arr[key]=value

        return self
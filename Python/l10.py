import datetime

class wrongPesel(Exception):
    pass

def checkPesel(pesel,date,sex):
    
    if len(pesel) != 11 or not pesel.isdecimal():
        raise wrongPesel
    
    if int(pesel[:2]) != date.year % 100:
        raise wrongPesel
    
    MonthCorrection = {18 : 80, 19 : 0, 20: 20, 21:40, 22:60}
    
    if int(pesel[2:4]) - MonthCorrection[date.year//100] != date.month :
        raise wrongPesel

    if int(pesel[4:6]) != date.day:
        raise wrongPesel
    
    if int(pesel[9])%2==0 and sex.lower() == "m":
        raise wrongPesel

    if int(pesel[9])%2==1 and sex.lower() == "f":
        raise wrongPesel

    sum = 0
    weight = (1,3,7,9,1,3,7,9,1,3)
    
    for i,char in enumerate(pesel[:-1]):
        sum+=int(char) * weight[i]

    if int(pesel[10]) !=  (10 - (sum % 10))%10:
        raise wrongPesel

    return True

try:
    print(checkPesel("02070803628",datetime.date(1902,7,8),"f"))
    print(checkPesel("02270803624",datetime.date(2002,7,8),"f"))
    print(checkPesel("02270812350",datetime.date(2002,7,8),"M"))
    print(checkPesel("02330812350",datetime.date(2002,7,8),"M"))
except wrongPesel:
    print("Wrong")


#2

#print((datetime.date.today() - datetime.date(2021,2 ,17)).days)

def averageAge(Liberal = False):
    res = 0
    count = 0
    with open("daty.in") as file:
        for line in file:
            try:
                res += (datetime.date.today() - datetime.date(int(line.split(" ")[2]),int(line.split(" ")[1]),int(line.split(" ")[0]))).days
                count+=1 
            except:
                if (Liberal):
                    continue
                raise
    
    return res/(count * 365)


print(averageAge(Liberal=True))

try:
    averageAge()
except:
    print("Exception")
    pass

#3
l=(1,2,3,4,5,6,7,8,9)

def checkPythagoras(seq):
    
    if len(seq) < 3:
        raise

    odd = 0
    even = 0

    for i in range(len(seq)-2):
        if seq[i]**2 + seq[i+1]**2  == seq[i+2]**2:
            for j in range(i,i+3):
                if (seq[j]%2 == 1):
                    odd += 1
                else:
                    even += 1
        
        if i < len(seq)-3:
            if seq[i]**2 + seq[i+1]**2 + seq[i+2]**2 == seq[i+3]**2:
                for j in range(i,i+4):
                    if (seq[j]%2 == 1):
                        odd += 1
                    else:
                        even += 1
    

    if (odd == even and odd == 0):
        raise

    return even,odd

print(*checkPythagoras(l))
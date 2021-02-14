a,b,c=input().split(' ')

a=int(a)
b=int(b)
c=int(c)
d=(b**2+c**2)**(1/2)
print(str(int(a*b/d))+' '+str(int(a*c/d)))

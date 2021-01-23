a,b=input().split(' ')
s=input().split(' ')

a=int(a)
b=int(b)

m=a*b
for i in s:
    print(int(i)-m,end=' ')


import math

n,m=input().split(' ')

n=int(n)
m=int(m)

print(math.factorial(n)//math.factorial(m)//math.factorial(n-m))

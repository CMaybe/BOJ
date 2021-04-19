from math import gcd

m = int(input())
s=[]
n=[]
ans = 0
for _ in range(0,m):
    t1,t2=input().split(' ')
    t1=int(t1)
    t2=int(t2)
    t=gcd(t1,t2)
    t1=t1//t
    t2=t2//t
    print(t1)
    print(t2)
    ans+= t2 * pow(int(t1),-1,1000000007)
    ans = ans%1000000007

print(ans)






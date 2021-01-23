a=[1,1,2,2,2,8]
b=input().split(' ')
c=[m-int(n) for m,n in zip(a,b)]
for n in c:
    print(n,end=' ')


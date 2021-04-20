n =int(input())

fibo = [0,1,1,2]

for i in range(4,n+1):
    fibo += [fibo[i-1]+fibo[i-2]]

print(fibo[n])


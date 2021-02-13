num = int(input())
s= input()

M=1234567891
r=31
ans=0
for i in range(num):
    ans+=(ord(s[i])-ord('a')+1)*pow(r,i,M)
    
print(ans%M)

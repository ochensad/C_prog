import sys
S=list(map(int,input().split()))
sum_01=0
n=sys.argv[1]
for i in range(len(S)):
	sum_01+=S[i]
print(n,sum_01/len(S))
import sys
import random

n = int(sys.argv[1])

print(n)
for i in range(n):
	print(random.randint(-100000,100000))
import numpy as np
import random
n = 10
r = 5.0

# arr = random.sample(random(0,90),n)

# print(arr)

# distance = np.array(arr,dtype=float)/10

# distance = sorted(distance)

arr = []
pre =float(2*r)
arr.append(pre)
for i in range(n):
	pre = pre+ r*2+ 10*random.random()
	pre = float("%.2f" % pre)
	arr.append(pre)
print(arr)

for i in range(n):
	# print('[i]')
	print('[%d]'% (i+1)),
	print(arr[i]),


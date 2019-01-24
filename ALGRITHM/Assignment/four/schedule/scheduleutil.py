import random
import numpy as np

n = 10;
k = 20;

arr = random.sample(range(16,40),k)
print(arr)
course = []


for i in range(n):
	course.append(arr[2*i:2*i+2])
print(course)
course = np.array(course,dtype = float)/2
arr = sorted(arr)
print(arr)
arr = np.array(arr,dtype = float)/2
print(arr)
for i,a in enumerate(course):
	course[i] = sorted(a)
print(course)

map2id = {a: i for i,a in enumerate(arr)}
print(map2id)
# words2ids = {v: k for k, v in ids2words.items()}


timeids = []

for i,a in enumerate(course):
	ids = []
	ids.append(map2id[a[0]])
	ids.append(map2id[a[1]])
	timeids.append(ids)
print(timeids)

occpy = np.zeros([k+1,n+1],dtype=int)
for i,a in enumerate(timeids):
	for j in range(a[0],a[1]):
		occpy[j+1][i+1] = 1
for i in range(n+1):
	occpy[0][i] = i
for i in range(k+1):
	occpy[i][0] = i

print(occpy)




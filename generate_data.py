#!/usr/bin/env python3


import random 


data=""
for n in range(0,1000):
	s = random.randrange(0,129)
	data += " {}".format(s)
print(data)
free=""
for n in range(0,1000):
	s = random.randrange(0,2)
	free += " {}".format(s) 
print(free)


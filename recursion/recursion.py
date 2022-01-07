#!/usr/bin/python3

import sys 
# sys.setrecursionlimit(150)

def showDollRussian(doll):
	if(doll == 1):
		print('All doll showed')
	else:
		showDollRussian(doll-1)


# showDollRussian(10≤)

def factorial(n):
	assert n >= 0 and int(n) == n, "The number must be positive integer"
	if n in [ 0, 1 ]:
		return 1
	else:
		print(n, '121')
		return n * factorial(n-1)
		
	
# print(factorial(149))

def fibonaci(n):
	assert n >= 0 and int(n) == n, "The number must be positive and integer number"
	if n in [0, 1]:
		return 1 
	else:
		# print(n)
		return fibonaci(n-1)+ fibonaci(n-2)

print(fibonaci(6))

	

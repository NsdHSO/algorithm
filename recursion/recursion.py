#!/usr/bin/python3

import sys 
import math
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
	if n in [ 0,1]:
		return n 
	else:
		# print(n)
		return fibonaci(n-1)+ fibonaci(n-2)

# print(fibonaci(600))

def findNumber(n):
	assert n >= 0 and int(n) == n, "The number must be positive and interger number"
	if n == 0:
		return 0
	else:
		return findNumber(int(n/10))+ int(n%10)

# print(findNumber(12))

def powerNumber(base, exponent):
	assert base>=0 and exponent >= 0 and int(exponent)== exponent, "The base or the exponent must be positive or integer number"
	if exponent == 0:
		return 1

	if base == 1:
		return base

	
	return powerNumber(base,int(exponent-1)) * base

# print(powerNumber(2.2, 7)i)

def greatestCommon(first, last):
	if(first < 0):
		first = -1 * first
	if(last < 0 ):
		last = -1 * last

	assert int(first) == first and int(last) == last , "Modulo at 0"
	if last == 0 :
		return first

	return greatestCommon(last, first % last)
# print(greatestCommon(-48,0))
# 2n = 
def decimalNumber(number):
	assert int(number), "Should to be a integer number"
	if(number ==0):
		return 0
	else:
		return number % 2 + 10 * decimalNumber(int(number/2))


# print(decimalNumber(-10))

array = [1,2,[[[[[4]]]],3,[[[[2,[2,[22]]]]]]]]
def flatten(n):
	results = []
	for result in n:
		if type(result) is list:
			print("if",result)
			results.extend(flatten(result))
		else: 
			print('elese', result)
			results.append(result)
	return results

# print(flatten(array))

array = ["sami", 'andrei', 'ema']

def capitalize(arr):
	results = []
	if(len(arr) == 0):
		return results
	results.append(arr[0][0].upper() + arr[0][1:])
	return results+capitalize(arr[1:])
	
print(capitalize(array))

def sum (n):
	if n<=0:
		return 0
	else:
		return n+ sum(n-1)

print(sum(3))

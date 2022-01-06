#!/usr/bin/python3

def showDollRussian(doll):
	if(doll == 1):
		print('All doll showed')
	else:
		showDollRussian(doll-1)


showDollRussian(10)

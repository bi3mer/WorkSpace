import random
import math

def makeLength(string, val, seedPower):
	if len(string) >= seedPower:
		return string
	else:
		return makeLength(string + val, val, seedPower)

def checkBottom(string, seedPower):
	if "1" in string:
		pass
	else:
		num = int(random.random() * seedPower)
		string = string[:num] + "1" + string[num + 1:]
	return string

def checkTop(string, seedPower):
	if "0" in string:
		pass
	else:
		num = int(random.random() * seedPower)
		string = string[:num] + "0" + string[num + 1:]
	return string

def formatString(string, seedPower):
	string = makeLength(string, string[len(string) - 1], seedPower)
	string = checkTop(checkBottom(string, seedPower), seedPower)
	return string

def dec_to_bin(x):
	return str(bin(x)[2:])

def makeMatrixString(seedType, seedPower):
	return formatString(dec_to_bin(int(random.random() * math.pow(seedType, seedPower))), seedPower)

def makeMatrixFromString(string, seedType, seedPower, wallNum, groundNum):
	matrix = [[wallNum for y in xrange(seedPower)] for x in range(2)]
	previousVal = string[0]
	for i in range(len(string)):
		val = int(string[i])
		if previousVal != val:
			matrix[int(previousVal)][i] = str(groundNum)
		matrix[val][i] = groundNum
		previousVal = string[i]
	return matrix
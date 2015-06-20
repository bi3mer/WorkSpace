# Colan Biemer
import math
import random
import MatrixString

count = 0

wallNum = 1
groundNum = 0
notBuildNum = -1

steps = 22
seedPower = 8
seedType = 2

## Procedurally create maps
procMap = []

def printMapRegular(newMap):
	for row in newMap:
		string = ""
		for cell in row:
			string += str(cell)
		print string



def makeRow():
	matrix = []
	appendedOnce = False
	position = 0
	for i in range(steps):
		# Generate matrix
		string = MatrixString.makeMatrixString(seedType, seedPower)
		newMatrix = MatrixString.makeMatrixFromString(string, seedType, seedPower, wallNum, groundNum)

		# Check new matrix
		if appendedOnce:
			height = len(matrix) - 1
			if matrix[height][len(matrix[height]) - 1] == groundNum:
				newMatrix[1][0] = groundNum
			else:
				newMatrix[0][0] = groundNum
		else:
			appendedOnce = True

		# Append new matrix
		for j in range(len(newMatrix)):
			for k in range(len(newMatrix[0])):
				matrix[j].append(newMatrix[j][k])

	return matrix

def appendToProcMap(matrix):
	for i in range(len(matrix)):
		procMap.append(matrix[i])

def connectFarRow():
	found = False

	## Look for paths
	for i in range(seedPower):
		if procMap[len(procMap) - 2][len(procMap[0]) - seedPower + i] == groundNum and procMap[len(procMap) - 3][len(procMap[0]) - seedPower + i]:
			found = True
			break

	## No path found
	if found == False:
		height = len(procMap) - 2
		procMap[height][len(procMap[height]) - 1 - int(random.random() * (seedPower - 1))] = groundNum

def connectCloseRow():
	found = False

	## Look for paths
	for i in range(seedPower):
		if procMap[len(procMap) - 2][i] == groundNum and procMap[len(procMap) - 3][i]:
			found = True
			break

	## No path found
	if found == False:
		procMap[len(procMap) - 2][int(random.random() * (seedPower - 1))] = groundNum




def makeMatrix():
	appendToProcMap(makeRow())
	for i in range(steps - 1):
		appendToProcMap(makeRow())
		connectFarRow()
makeMatrix()
printMapRegular(procMap)
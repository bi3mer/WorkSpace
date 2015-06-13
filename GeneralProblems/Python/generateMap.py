## Colan Biemer
import random

wall = 1
ground = 0

xBoundaryMax = 20
xBoundaryMin = 0
yBoundaryMax = 20
yBoundaryMin = 0

chanceToLive = .3
numSteps = 5
groundLimit = 3
wallLimit = 3

def printMapBig(procMap):
	for row in procMap:
		string1 = ""
		string2 = ""
		for cell in row:
			string1 += str(cell) + str(cell)
			string2 += str(cell) + str(cell)
		print string1
		print string2

def printMapRegular(procMap):
	for row in procMap:
		string = ""
		for cell in row:
			string += str(cell)
		print string

def printAroundCell(procMap, x , y):
	for i in range(3):
		yCor = i -1
		string = ""
		for j in range(3):
			xCor = j -1
			if safeBoundary(xCor + x, yCor + y):
				string += str(procMap[yCor + y][xCor + x])
		print string


def safeBoundary(x, y):
	if x > xBoundaryMin and x != xBoundaryMax - 1 and y != yBoundaryMin and y != yBoundaryMax -1:
		return True
	return False

def countAliveGrounds(procMap, x, y):
	count = 0
	if safeBoundary(x - 1, y) and procMap[y][x - 1] == ground:
		count += 1
	if safeBoundary(x , y + 1) and procMap[y + 1][x] == ground:
		count += 1
	if safeBoundary(x , y - 1) and procMap[y - 1][x] == ground:
		count += 1
	if safeBoundary(x + 1, y) and procMap[y][x + 1] == ground:
		count += 1
	return count

def countAliveWalls(procMap, x, y):
	count = 0
	if safeBoundary(x - 1, y) and procMap[y][x - 1] == wall:
		count += 1
	if safeBoundary(x , y + 1) and procMap[y + 1][x] == wall:
		count += 1
	if safeBoundary(x , y - 1) and procMap[y - 1][x] == wall:
		count += 1
	if safeBoundary(x + 1, y) and procMap[y][x + 1] == wall:
		count += 1
	return count

def simuationStep(procMap):
	newMap = [[wall for y in xrange(yBoundaryMax)] for x in xrange(xBoundaryMax)]
	for y in range(len(procMap)):
		for x in range(len(procMap[0])):
			if safeBoundary(x, y): 
				groundsAlive = countAliveGrounds(procMap, x, y)
				wallsAlive = countAliveWalls(procMap, x, y)
				if wallsAlive >= wallLimit:
					pass
				elif groundLimit > groundLimit:
					procMap[y][x] = ground
				elif procMap[y][x] == wall:
					if groundsAlive < groundLimit:
						newMap[y][x] = ground
				else:
					if wallsAlive <= wallLimit:
						newMap[y][x] = ground


	return newMap

## Procedurally create maps
procMap = [[wall for y in xrange(yBoundaryMax)] for x in xrange(xBoundaryMax)]

## Randomly place cells for walls
for i in range(xBoundaryMax):
	for j in range(yBoundaryMax):
		if safeBoundary(i, j) and random.random() > chanceToLive:
			procMap[i][j] = ground

for i in range(numSteps):
	procMap = simuationStep(procMap)

printMapBig(procMap)
print "\n------------------\n"
printMapRegular(procMap)
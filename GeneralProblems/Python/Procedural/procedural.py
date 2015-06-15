## Colan Biemer
import random


wall = 1
ground = 0

xBoundaryMax = 50
xBoundaryMin = 0
yBoundaryMax = 50
yBoundaryMin = 0

chanceToLive = .3
numSteps = 10
birthLimit = 3
deathLimit = 2

def printMap(procMap):
	for row in procMap:
		string = ""
		for cell in row:
			string += str(cell)
		print string

def safeBoundary(x, y):
	if x > xBoundaryMin and x != xBoundaryMax - 1 and y != yBoundaryMin and y != yBoundaryMax -1:
		return True
	return False

def countAliveNeighbors(procMap, x, y):
	count = 0
	for i in range(3):
		yCor = i -1
		for j in range(3):
			xCor = j -1
			if yCor != 0 and xCor != 0 and safeBoundary(xCor + x, yCor + y) and procMap[yCor + y][xCor + x] == ground:
				count += 1
	return count


def simuationStep(procMap):
	newMap = [[wall for y in xrange(yBoundaryMax)] for x in xrange(xBoundaryMax)]
	for y in range(len(procMap)):
		for x in range(len(procMap[0])):
			if safeBoundary(x, y): 
				neighborsAlive = countAliveNeighbors(procMap, x, y) 
				if procMap[y][x] == ground:
					if neighborsAlive < deathLimit:
						newMap[y][x] = wall
					else:
						newMap[y][x] = ground
				else:
					if neighborsAlive > birthLimit:
						newMap[y][x] = ground
					else:
						newMap[y][x] = wall

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

printMap(procMap)
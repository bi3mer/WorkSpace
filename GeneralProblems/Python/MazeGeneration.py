#!/bin/python
from random import randrange
import sys

## Board sizes
WIDTH  = 20 #20
HEIGHT = 23 #23

## Types in Board
PATH = '.'
WALL  = 0
START = 2
END   = 3
CELL = 7

## Directions
EAST       = [ 1,  0]
WEST       = [-1,  0]
SOUTH      = [ 0,  1]
NORTH      = [ 0, -1]
DIRECTIONS = [NORTH, EAST, SOUTH, WEST]

NORTHEAST = [ 1, -1]
SOUTHEAST = [ 1,  1]
SOUTHWEST = [-1, -1]
NORTHWEST = [-1,  1]

ALLDIRECTIONS = [NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST]

## Board
BOARD = [[CELL for y in xrange(WIDTH)] for x in xrange(HEIGHT)]

## Print the board, in a formatted way
def PrintBoardDouble():
	## for each row
	for row in BOARD:
		## create string to represent rwo
		string = ""

		## get each cell in row
		for cell in row:
			## add cell to row
			string += str(cell) + str(cell)

		## print stngified row
		print string
		print string

def findCells(x, y, cellType, directions):
	## List of walls
	nearByWalls = []

	## Check directions
	for direction in directions:
		if(     x + direction[0] < WIDTH  and x + direction[0] >= 0 
			and y + direction[1] < HEIGHT and y + direction[1] >= 0 
			and BOARD[y + direction[1]][x + direction[0]] == cellType):

			## Add cell to list
			nearByWalls.append([x + direction[0], y + direction[1]])

	return nearByWalls

## find nearby walls and add coordiantes to list, NOTE: does all 8 directions
def FindAllNearByCellTypes(x, y, cellType):
	return findCells(x, y, cellType, ALLDIRECTIONS)

## find nearby walls and add coordiantes to list, NOTE: only does NESW not all 8 directions
def FindNearbyCellTypes(x, y, cellType):
	return findCells(x, y, cellType, DIRECTIONS)

## Run algorithm similar to prim, but modified to put walls in the matrix
def RandomizedPrimMatrix():
	## pick random cell
	randomCellX = randrange(0, WIDTH)
	randomCellY = randrange(0, HEIGHT)

	## add random cell to board
	BOARD[randomCellY][randomCellX] = PATH

	## list of nearby cells with start cells nearby
	nearByCells = FindNearbyCellTypes(randomCellX, randomCellY, CELL)

	## Run through until no nearby walls exists
	while len(nearByCells) > 0:
		## Get random cell
		index = randrange(0, len(nearByCells))
		randomCellCoordinates = nearByCells[index]

		## Remove cell from frontier
		nearByCells = nearByCells[: index] + nearByCells[index + 1 :]

		## check is the cell in the direction is not in the maze yet
		if BOARD[randomCellCoordinates[1]][randomCellCoordinates[0]] == CELL:
			## Find cells that apart of the path
			nearByPathCells = FindAllNearByCellTypes(randomCellCoordinates[0], randomCellCoordinates[1], PATH)
			print "randCellCoord:   " + str(randomCellCoordinates)
			print "Nearbypathcells: " + str(nearByPathCells)

			## check for max # of nearby path cells
			if len(nearByPathCells) >= 3:
				## Create wall
				BOARD[randomCellCoordinates[1]][randomCellCoordinates[0]] = WALL
			else:
				## Add to path
				BOARD[randomCellCoordinates[1]][randomCellCoordinates[0]] = PATH

				## Expand frontier
				nearByCells += FindNearbyCellTypes(randomCellCoordinates[0], randomCellCoordinates[1], CELL)

		print "randomCellCoordinates: " + str(randomCellCoordinates) 
		print "nearByCells: " + str(nearByCells)
		PrintBoardDouble()
		print "---------------------------------------\n"

RandomizedPrimMatrix()
PrintBoardDouble()


'''
## Use the algorithm RandomizedPrim to generate a maze
def RandomizedPrim():
	## pick random cell
	randomCellX = int(random.random() * (WIDTH - 1))
	randomCellY = int(random.random() * (HEIGHT - 1))

	## add random cell to board
	BOARD[randomCellY][randomCellX] = PATH

	## list of nearby walls
	nearByWalls = []

	## add nearby walls to list
	nearByWalls += FindNearbyCellTypes(randomCellX, randomCellY, CELL)

	## Run through until no nearby walls exists
	while len(nearByWalls) > 0:
		## Get random cell
		index = int(random.random() * (len(nearByWalls) - 1))
		randomCellCoordinates = nearByWalls[index]

		## Get random direction
		randomDirection = DIRECTIONS[int(random.random() * (len(DIRECTIONS) - 1))]

		## check is the cell in the direction is not in the maze yet
		if BOARD[randomCellCoordinates[1]][randomCellCoordinates[0]] == CELL:
			## make sure random direction is valid
			while randomCellCoordinates[1] + randomDirection[1] >= HEIGHT or randomCellCoordinates[1] + randomDirection[1] < 0 
			or randomCellCoordinates[0] + randomDirection[0] >= WIDTH or randomCellCoordinates[0] + randomDirection[0] < 0:
				## Get new random direction
				randomDirection = DIRECTIONS[int(random.random() * (len(DIRECTIONS) - 1))]

			## Make the wall a passage
			BOARD[randomCellCoordinates[1] + randomDirection[1]][randomCellCoordinates[0] + randomDirection[0]] = PATH

			## Check for cells that need to be declared as a wall
			nearByCells = FindAllNearByCellTypes(randomCellCoordinates[1] + randomDirection[1], randomCellCoordinates[0] + randomDirection[0], PATH)
			for cell in nearByCells:
				## Check if there are too many cells nearby
				if len(FindAllNearByCellTypes) >= 3:
					BOARD[cell[1]][cell[0]] = WALL

			## Add the neighboring walls of the cell to the wall list
			nearByWalls += FindNearbyCellTypes(randomCellCoordinates[0] + randomDirection[0], randomCellCoordinates[1] + randomDirection[1], CELL)

		## Remove cell from the list
		nearByWalls = nearByWalls[: index] + nearByWalls[index + 1 :]



## Loop  through shuffled directions
for direction in DIRECTIONS:
	## check if direction is valid
	if randomCellCoordinates[1] + direction[1] >= HEIGHT or randomCellCoordinates[1] + direction[1] < 0 or randomCellCoordinates[0] + direction[0] >= WIDTH or randomCellCoordinates[0] + direction[0] < 0:
		## set direction and break
		randomDirection = direction
		break
'''
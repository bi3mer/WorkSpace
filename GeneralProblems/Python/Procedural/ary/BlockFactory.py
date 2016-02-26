import random
import Print

class BlockFactory:
	def __init__(self, height, width, wall, ground):
		self.height = height
		self.width = width
		self.wall = wall
		self.ground = ground
		self.startingYPoint = 0
		self.endingYPoint = 0	

	def generateMatrixArray(self):
		arr = []
		for i in range(self.width):
			arr.append(random.randint(0, self.height - 1))

		return arr

	def connectPath(self, previousYPosition, currentXPosition, currentYPosition):
		if previousYPosition != currentYPosition:
			direction = 1
			if currentYPosition > previousYPosition:
				direction = -1
			while currentYPosition != previousYPosition:
					currentYPosition += direction
					self.block[currentYPosition][currentXPosition] = self.ground


	def createBlocK(self):
		## instantiate block
		self.block = [[self.wall for y in xrange(self.width)] for x in xrange(self.height)]

		firstTime = True
		previousYPosition = 0
		arr = self.generateMatrixArray()
		for i in range(self.width):
			
			self.block[arr[i]][i] = self.ground
			if firstTime:
				self.startingYPoint = arr[i]
				firstTime = False
			else:
				self.connectPath(previousYPosition, i, arr[i])
			
			previousYPosition = arr[i]

		# for i in range(self.height):
		# 	if self.block[i][self.width - 1] == self.ground:
		# 		self.endingYPoint = i
		# 		break
		self.endingYPoint = arr[self.width - 1]

	def connectBlockHorizontal(self, oldYPosition):
		direction = 1
		if oldYPosition <= self.startingYPoint:
			direction = -1
		while self.startingYPoint != oldYPosition:
			self.startingYPoint += direction
			self.block[self.startingYPoint][0] = self.ground

	def connectBlockVerticallyDown(self, x):
		direction = -1
		lowestY = 0
		for i in range(self.height):
			if self.block[i][x] == self.ground:
				lowestY = i

		while lowestY < self.height:
			self.block[lowestY][x] = self.ground
			lowestY += 1

	def connectBlockVerticallyUp(self, x):
		direction = 1
		tallestY = self.height
		for i in range(self.height):
			if self.block[i][x] == self.ground:
				tallestY = i
				break

		while tallestY >= 0:
			self.block[tallestY][x] = self.ground
			tallestY -= 1

	def getCell(self, height, width):
		return self.block[height][width]

	def getBlock(self):
		return self.block

	def getStartingYPoint(self):
		return self.startingYPoint

	def getEndingYPoint(self):
		return self.endingYPoint


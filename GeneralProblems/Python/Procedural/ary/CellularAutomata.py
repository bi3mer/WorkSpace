class CellularAutomata:
	## configurable
	changeToDead = 3
	changeToAlive = 1

	def __init__(self, matrix, steps, alive, dead):
		self.matrix = matrix
		self.steps = steps
		self.alive = alive
		self.dead = dead
		self.height = len(matrix)
		self.width = len(matrix[0])

	def checkBoundary(self, xPos, yPos):
		if xPos >= 0 and xPos < self.width and yPos >= 0 and yPos < self.height:
			return True
		return False

	def deadCount(self, xPos, yPos):
		wallCount = 0
		if self.checkBoundary(xPos + 1, yPos) and self.matrix[yPos][xPos + 1] == self.dead:
			wallCount += 1
		if self.checkBoundary(xPos - 1, yPos) and self.matrix[yPos][xPos - 1] == self.dead:
			wallCount += 1
		if self.checkBoundary(xPos, yPos + 1) and self.matrix[yPos + 1][xPos] == self.dead:
			wallCount += 1
		if self.checkBoundary(xPos, yPos - 1) and self.matrix[yPos - 1][xPos] == self.dead:
			wallCount += 1
		return wallCount

	def runStep(self):
		for i in range(self.height):
			for j in range(self.width):
				deadCount = self.deadCount(j, i)
				if self.matrix[i][j] == self.alive and deadCount >= self.changeToDead:
					self.matrix[i][j] = self.dead
				elif deadCount <= self.changeToAlive:
					self.matrix[i][j] = self.alive

	def runAutomata(self):
		for i in range(self.steps):
			self.runStep()

	def getMatrix(self):
		return self.matrix
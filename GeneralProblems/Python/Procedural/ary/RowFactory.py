from BlockFactory import BlockFactory
import random
import Print

class RowFactory:
	def __init__(self, steps, height, width, wall, ground):
		self.steps = steps
		self.height = height
		self.width = width
		self.wall = wall
		self.ground = ground
		self.row = []

	def connectRowsVertically(self, oldRow):
		index = 0
		for i in range(self.steps):
			## chose x point for blocks to meet
			xPoint = random.randint(0, self.width - 1)

			## Connect blocks at x point
			oldRow.getRow()	[i].connectBlockVerticallyDown(xPoint)
			self.row[i].connectBlockVerticallyUp(xPoint)

	def appendBlock(self):
		bf = BlockFactory(self.height, self.width, self.wall, self.ground)
		bf.createBlocK()
		self.row.append(bf)

	def addBlock(self):
		## create block
		bf = BlockFactory(self.height, self.width, self.wall, self.ground)
		bf.createBlocK()

		## connect blocks
		lastBlockIndex = len(self.row) - 1
		endingYPoint = self.row[lastBlockIndex].getEndingYPoint()
		if endingYPoint != bf.getStartingYPoint():
			bf.connectBlockHorizontal(endingYPoint)

		## add block to row
		self.row.append(bf)

	def createRow(self):
		self.appendBlock()
		for i in range(self.steps - 1):
			self.addBlock()

	def getRow(self):
		return self.row

	def getRowMatrix(self):
		rowMatrix = [[] for y in xrange(self.steps)]
		for block in self.row:
			blockMatrix = block.getBlock()
			for i in range(len(blockMatrix)):
				for blockCell in blockMatrix[i]:
					rowMatrix[i].append(blockCell)
		return rowMatrix
			

import random
import Print
from RowFactory import RowFactory

class Map: 
	def __init__(self, steps, height, width, wall, ground):
		self.steps = steps
		self.height = height
		self.width = width
		self.wall = wall
		self.ground = ground
		self.map = []

	def appendRow(self):
		rf = RowFactory(self.steps, self.height, self.width, self.wall, self.ground)
		rf.createRow()
		self.map.append(rf)

	def addRow(self):
		rf = RowFactory(self.steps, self.height, self.width, self.wall, self.ground)
		rf.createRow()
		rf.connectRowsVertically(self.map[len(self.map) - 1])

		self.map.append(rf)


	def createMap(self):
		self.appendRow()
		for i in range(self.steps - 1):
			self.addRow()

	def createMapMatrix(self):
		matrix = []
		for row in self.map:
			for blockRow in row.getRowMatrix():
				matrix.append(blockRow)
		return matrix
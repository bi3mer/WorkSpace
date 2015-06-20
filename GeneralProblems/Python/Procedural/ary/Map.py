import random
import Print
from RowFactory import RowFactory
from CellularAutomata import CellularAutomata

class Map: 
	def __init__(self, steps, height, width, wall, ground, automataSteps):
		self.steps = steps
		self.height = height
		self.width = width
		self.wall = wall
		self.ground = ground
		self.map = []
		self.automataSteps = automataSteps

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

	def createStartLocation(self, matrix):
		if matrix[0][0] != self.ground:
			x = 0
			y = 0
			while matrix[y][x] != self.ground:
				for i in range(2):
					matrix[y][x] = self.ground
				y += 1

		return matrix

	def createMapMatrix(self):
		matrix = []
		for row in self.map:
			for blockRow in row.getRowMatrix():
				matrix.append(blockRow)
		return self.createStartLocation(matrix)

	def createMapMatrixAutomata(self):
		matrix = []
		for row in self.map:
			for blockRow in row.getRowMatrix():
				matrix.append(blockRow)

		ca = CellularAutomata(matrix, self.automataSteps, self.ground, self.wall)
		ca.runAutomata()
		return self.createStartLocation(ca.getMatrix())
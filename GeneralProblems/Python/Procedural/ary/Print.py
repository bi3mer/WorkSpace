def big(newMap):
	for row in newMap:
		string1 = ""
		string2 = ""
		for cell in row:
			string1 += str(cell) + str(cell)
			string2 += str(cell) + str(cell)
		print string1
		print string2

def reg(newMap):
	for row in newMap:
		string = ""
		for cell in row:
			string += str(cell)
		print string
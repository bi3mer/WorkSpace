from RowFactory import RowFactory
from BlockFactory import BlockFactory
from Map import Map
import Print

height = 5
width = 6
steps = 14
automataSteps = 20

wall  = 1
ground = 0

def main():
	# for i in range(10):
	# 	bf = BlockFactory(height, width, wall, ground)
	# 	bf.createBlocK()
	# 	Print.big(bf.getBlock())
	# 	print "---------------"
	# rf = RowFactory(steps, height, width, wall, ground)
	# rf.createRow()
	# Print.big(rf.getRowMatrix())
	m = Map(steps, height, width, wall, ground, automataSteps)
	m.createMap()
	Print.big(m.createMapMatrix())
	print "\n\n\n\n\n"
	Print.big(m.createMapMatrixAutomata())

if __name__ == "__main__":
    main()

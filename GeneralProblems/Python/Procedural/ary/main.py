from RowFactory import RowFactory
from BlockFactory import BlockFactory
from Map import Map
import Print

height = 5
width = 6
steps = 14
automataSteps = 2

wall  = 1
ground = 0

def main():
	m = Map(steps, height, width, wall, ground, automataSteps)
	m.createMap()
	Print.big(m.createMapMatrix())
	print "\n\n\n\n\n"
	Print.big(m.createMapMatrixAutomata())

if __name__ == "__main__":
    main()

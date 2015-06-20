'''
This solves the following problem:
There is a hallway of 100 lockers and all of them closed and person X follows the following steps.
1. Toggles all the lockers.
2. Toggles every second locker.
3. Toggles every third locker.
4. Toggles every fourth locker.
...
100. Toggles every 100th locker.

How many lockers are open after the 100th step.

Here are the steps if we were only doing 4 lockers and 4 steps where 0 is open and _ is closed:
0 0 0 0
0 _ 0 _
0 _ _ _
0 - - 0

There is a pattern here where you can solve the problem mathematically but I only provide the programtic approach. 
I may implement the math version in a future version. 

- Colan
'''

def locker(array, steps, step): 
	## time complexity   0(n^2)
	## space complexity	 0(n), assuming the tail recursion is well implemented.

	## you'll notice both if statements do something similar, and if we assume good input we could cut it down to one
	## but I'll be a pessimist here.
	if len(array) < step: 
		return array
	if step > steps: 
		return array
	for i in range(len(array)):
		if (i+1)%step == 0: ## checks if a toggle state has been reached.
			if array[i] == 0:
				array[i] = 1
			else:
				array[i] = 0
	step+=1
	## Note recursion in Python is not a good step, even though this is tail recursion. 
	## If this wasn't for practice I would recommend a double for loop.
	return locker(array,steps,step)

arrayLength = 100 ## this defines how many lockers there are and how many steps person X will take.
array = []
for i in range(arrayLength):
	array.append(0)
array = locker(array,arrayLength,1)
count = 0
for i in array:
	if i == 1:
		count+=1
print "There are", arrayLength, "lockers and", count, "are open."
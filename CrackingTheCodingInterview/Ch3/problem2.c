#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Have a stack also store the min value at all times.

The first solution is to store the min into a second stack each time an element is added.
A better solution is to only add a new min when a new min is found, or is equal to the min.

- Colan
*/

#define STACK_SIZE 100

struct Stack
{
	int data[STACK_SIZE];
	int size;
};

typedef struct Stack Stack;

struct StackMin
{
	Stack *stack;
	Stack *min;
};

typedef struct StackMin StackMin;

StackMin *initStackMin();
int popMin(StackMin *);
void pushMin(StackMin *,int);
int peekMin(StackMin *);
int getMin(StackMin *);

Stack * initStack();
int pop(Stack *);
void push(Stack *,int);
int peek(Stack *);

int main(){
	srand(time(NULL));
	StackMin *stack = initStackMin();
	for(int i = 0;i<10;i++)
		pushMin(stack,rand()%100);
	for(int i = 0;i<10;i++){
		printf("Min: %i\n",getMin(stack));
		printf("Pop: %i\n",popMin(stack));
	}
}

StackMin *initStackMin(){
	StackMin *stackMin = (StackMin *) calloc( 1, sizeof(stackMin));
	stackMin->stack    = initStack();
	stackMin->min      = initStack();
	return stackMin;
}

int popMin(StackMin *stack){
	int popVal = pop(stack->stack);
	if(popVal == peek(stack->min)){
		pop(stack->min);
	}
	return popVal;
}

void pushMin(StackMin *stack,int val){
	if(val <= peek(stack->min) || stack->stack->size == 0) // either new min is found or there is no min yet.
		push(stack->min,val);
	push(stack->stack,val);
}

int peekMin(StackMin *stack){
	return peek(stack->stack);
}
int getMin(StackMin *stack){
	return peek(stack->min);
}

int pop(Stack *stack){
	int temp = stack->data[stack->size];
	stack->data[stack->size] = 0;
	if(stack->size > 0)
		stack->size--;
	return temp;
}

void push(Stack *stack,int data){
	stack->size++;
	stack->data[stack->size] = data;
}

int peek(Stack *stack){
	return stack->data[stack->size];
}

Stack * initStack(){
	Stack *stack = (Stack *) calloc( 1, sizeof(Stack));
	stack->size = 0;
	return stack;
}


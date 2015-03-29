#include <stdio.h>
#include <stdlib.h>

/*
Implement a queue using two stacks.

The solution here will be pretty simple.

give 1

1

give 2

2 1

meaning we pop 1 and place into other stack, push 2, then pop 1 and push 1. etc.

- Colan
*/

#define STACK_SIZE 100

struct Stack
{
	int data[STACK_SIZE];
	int size;
};

typedef struct Stack Stack;

struct StackOfStacks
{
	Stack* stacks[STACK_SIZE];
	int size;
};

typedef struct StackOfStacks StackOfStacks;

StackOfStacks * initStackOfStacks();
int popStackOfStacks(StackOfStacks *);
void pushStackOfStacks(StackOfStacks *,int);
int peekStackOfStacks(StackOfStacks *);

Stack * initStack();
int pop(Stack *);
void push(Stack *,int);
int peek(Stack *);

int main(){
	StackOfStacks *stackOfStacks = initStackOfStacks();

	for(int i = 0;i<250;i++){
		printf("%i,", i);
		pushStackOfStacks(stackOfStacks,i);
	}
	printf("\n");
	for(int i = 0;i<250;i++)
		printf("Pop(%i): %i\n",i,popStackOfStacks(stackOfStacks));

	free(stackOfStacks->stacks);
	free(stackOfStacks);
}

StackOfStacks * initStackOfStacks(){
	StackOfStacks *stackOfStacks = (StackOfStacks *) calloc( 1, sizeof(StackOfStacks));
	stackOfStacks->size = 0;
	stackOfStacks->stacks[0] = initStack();
	return stackOfStacks;
}

void pushStackOfStacks(StackOfStacks *stackOfStacks,int val){
	int index = stackOfStacks->size%100;
	if(index > 0 && !peek(stackOfStacks->stacks[index]) && index > STACK_SIZE){
		stackOfStacks->stacks[index+1] = stackOfStacks->stacks[index];
		stackOfStacks->stacks[index] = initStack();
	}
	push(stackOfStacks->stacks[index],val);
}

int popStackOfStacks(StackOfStacks *stackOfStacks){
	int temp = pop(stackOfStacks->stacks[(stackOfStacks->size/100)%100]);
	printf("%i",(stackOfStacks->size/100)%100);
	stackOfStacks->size--;
	return temp;
}

int peekStackOfStacks(StackOfStacks *stackOfStacks){
	return peek(stackOfStacks->stacks[(stackOfStacks->size/100)%100]);
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

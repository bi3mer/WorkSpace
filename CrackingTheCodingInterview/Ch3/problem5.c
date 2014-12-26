#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

struct MyQueue{
	Stack *stackOne;
	Stack *stackTwo;
};

typedef struct MyQueue MyQueue;

MyQueue * initQueue();
void enQueue(MyQueue *,int);
int deQueue(MyQueue *);

Stack * initStack();
int pop(Stack *);
void push(Stack *,int);
int peek(Stack *);

int main(){
	srand(time(NULL));
	MyQueue *queue = initQueue();
	for(int i = 0;i<10;i++){
		enQueue(queue,i);
		printf("%i, ",i);
	}
	printf("\n");
	for(int i = 0;i<10;i++)
		printf("DeQueue: %i\n",deQueue(queue));
}

MyQueue * initQueue(){
	MyQueue *queue = (MyQueue *) calloc( 1, sizeof(MyQueue));
	queue->stackOne = initStack();
	queue->stackTwo = initStack();
	return queue;
}

void enQueue(MyQueue * queue, int val){
	while(queue->stackOne->size > 0)
		push(queue->stackTwo,pop(queue->stackOne));
	push(queue->stackOne,val);
	while(queue->stackTwo->size>0)
		push(queue->stackOne,pop(queue->stackTwo));
}

int deQueue(MyQueue * queue){
	return pop(queue->stackOne);
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


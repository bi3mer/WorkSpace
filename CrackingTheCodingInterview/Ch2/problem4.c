#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
partition list around value X
i.e. given 3
0 - 3 - 1 - 2 - 4
returns
0 - 1 - 2 - 4

or given 4
4 - 2 - 0 - 10 - 5 - 1
returns
2 - 0 - 1 - 4 - 10 - 5

orderListMethodOne: will create two lists, one lower and one higher, and then add the mid value plus the higher values.

- Colan
*/

struct node{
	int val;
	struct node * next;
};
struct node * initNode(int val);
void printList(struct node *);
void printNode(struct node *);
void addNewNode(struct node *, int);
void addNode(struct node *, struct node *);
void deleteNode(struct node *,struct node *);
void insertNode(struct node *);
void deleteList(struct node *);
void deleteVal(struct node *,int);
void removeDuplicates(struct node *);
void removeNode(struct node *);
void addList(struct node *, struct node *);
void partialOrderList(struct node *,int);

int main(){
	struct node *ptr = initNode(0);
	srand(time(NULL));
	for(int i = 1;i<10;i++){
		addNewNode(ptr,rand()%200);
	}
	addNewNode(ptr,100);
	printf("List: ");
	printList(ptr);
	
	printf("Order list around 100: ");
	partialOrderList(ptr,100);
	printList(ptr);

	deleteList(ptr);
}

void partialOrderList(struct node * ptr,int midVal){
	struct node * lower = NULL;
	struct node * mid   = NULL;
	struct node * upper = NULL;
	struct node * temp  = ptr;
	// Construct lists
	while(temp != NULL){
		if(temp->val > midVal){
			if(upper == NULL)
				upper = initNode(temp->val);
			else
				addNewNode(upper,temp->val);
		} else if(temp->val < midVal){
			if(lower == NULL)
				lower = initNode(temp->val);
			else
				addNewNode(lower,temp->val);
		} else {
			if(mid == NULL)
				mid = initNode(temp->val);
			else
				addNewNode(mid,temp->val);
		}
		temp = temp->next;
	}
	//combine lists
	addList(lower,mid);
	addList(lower,upper);
	//make ptr into lower
	ptr->next = lower->next;
	ptr->val = lower->val;
}

void addList(struct node * listOne, struct node * listTwo){
	if(listOne == NULL)
		listOne = listTwo;
	if(listTwo == NULL)
		return;
	while(listOne->next != NULL)
		listOne = listOne->next;
	listOne->next = listTwo;
}

void removeNode(struct node * ptr){
	struct node * temp = ptr->next;
	ptr->val = ptr->next->val;
	ptr->next = temp->next;
	free(temp);
}

struct node * initNode(int val){
	struct node *ptr = (struct node *) calloc( 1, sizeof(struct node ));
	if(ptr == NULL)
		return (struct node *) NULL;
	else{
		ptr->val  = val;
		ptr->next = NULL;
		return ptr;
	}
}

void printList(struct node *ptr){
	while(ptr->next!= NULL){
		printNode(ptr);
		ptr = ptr->next;
	}
	printf("%i\n",ptr->val);
}

void printNode(struct node *ptr){
	printf("%i->",ptr->val);
}

void addNewNode(struct node *ptr,int val){
	addNode(ptr,initNode(val));
}

void addNode(struct node * head, struct node * newNode){
	while(head->next != NULL)
		head = head->next;
	head->next = newNode;
}

void deleteNode(struct node *head,struct node *ptr){
	if(head == ptr){
		//printf("here\n");
		struct node * temp = head->next;
		head->val = head->next->val;
		head->next = temp->next;
		free(temp);
		return;
	}
	while(head->next != NULL && head->next != ptr)
		head = head->next;
	head->next = ptr->next;
	free(ptr);
}

void insertNode(struct node *ptr){};

void deleteList(struct node *ptr){
	struct node * tmp;
	while(ptr->next != NULL){
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

void deleteVal(struct node *ptr,int val){
	struct node *head = ptr;
	while(ptr != NULL){
		if(ptr->val == val)
			deleteNode(head,ptr);
		ptr=ptr->next;
	}
}

void removeDuplicates(struct node * ptr){
	while(ptr->next != NULL){
		deleteVal(ptr->next,ptr->val);
		ptr = ptr->next;
	}
}
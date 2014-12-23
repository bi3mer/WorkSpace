#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
find where the given list is circular.

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
int size(struct node *);
int findCircularVal(struct node *);


int main(){
	struct node *ptr    = initNode(6);
	struct node *circle = initNode(3);
	addNewNode(ptr,1);
	addNewNode(ptr,7);
	addNewNode(ptr,2);
	addNewNode(ptr,10);
	addNewNode(circle,20);
	addNewNode(circle,30);
	addNewNode(circle,40);
	addNode(circle,circle); // circle list circular
	addNode(ptr,circle);    // makes whole list circular
	printf("Value at start of circular list: %i\n",findCircularVal(ptr));
}

int findCircularVal(struct node * ptr){
	struct node * slow = ptr;
	struct node * fast = ptr;
	do {
		slow = slow->next;
		fast = fast->next;
		if(fast->next == NULL)
			return 0; // Will return 0 if the list is not circular.
		fast = fast->next;
	} while (fast->next != NULL && fast != slow);
	slow = ptr;
	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow->val;
}

int size(struct node * ptr){
	int total = 0;
	while(ptr->next != NULL){
		ptr = ptr->next;
		total++;
	}
	return total;
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
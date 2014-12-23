#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
addBackwardOrder:
given: (7 -> 1 -> 6) + (5 -> 9 -> 2) return 2 -> 1 -> 9
return:     617      +      295         =       912

addForwardOrder:
given: (6 -> 1 -> 7) + (2 -> 9 -> 5) return 9 -> 1 -> 2
return:     617      +      295         =       912 

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
int addBackwardOrder(struct node *, struct node *);
int addForwardOrder(struct node *, struct node *);
int convertBackward(struct node *);
int convertForward(struct node *);

int main(){
	struct node *oneForward = initNode(6);
	addNewNode(oneForward,1);
	addNewNode(oneForward,7);

	struct node *twoForward = initNode(2);
	addNewNode(twoForward,9);
	addNewNode(twoForward,5);

	struct node *oneBackward = initNode(7);
	addNewNode(oneBackward,1);
	addNewNode(oneBackward,6);

	struct node *twoBackward = initNode(5);
	addNewNode(twoBackward,9);
	addNewNode(twoBackward,2);

	printf("Forward add:  %i\n", addForwardOrder(oneForward,twoForward));
	printf("Backward add: %i\n", addBackwardOrder(oneBackward,twoBackward));

	deleteList(oneForward);
	deleteList(twoForward);
	deleteList(oneBackward);
	deleteList(twoBackward);
}


int convertBackward(struct node * ptr){
	int power = 0;
	int total = 0;
	while(ptr!=NULL){
		total += ptr->val * (int) pow(10,power);
		power++;
		ptr = ptr->next;
	}
	return total;
}

int convertForward(struct node * ptr){
	int power = size(ptr);
	int total = 0;
	while(ptr!=NULL){
		total += ptr->val * (int) pow(10,power);
		power--;
		ptr = ptr->next;
	}
	return total;
}

int addBackwardOrder(struct node *one, struct node *two){
	return convertBackward(one) + convertBackward(two);
}

int addForwardOrder(struct node *one, struct node *two){
	return convertForward(one) + convertForward(two);
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
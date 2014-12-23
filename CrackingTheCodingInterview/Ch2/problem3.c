#include <stdio.h>
#include <stdlib.h>

/*
remove given value from list
i.e.
0 - 1 - 2 - 4
given 1
0 - 2 - 4

You'll notice all I had to do was copy and paste the remove first node code.

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

int main(){
	struct node *ptr = initNode(0);
	for(int i = 1;i<10;i++){
		addNewNode(ptr,i);
	}
	printf("List: ");
	printList(ptr);
	
	printf("Remove second element element: ");
	removeNode(ptr->next);
	printList(ptr);

	deleteList(ptr);
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
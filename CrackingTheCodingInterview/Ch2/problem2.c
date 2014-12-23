#include <stdio.h>
#include <stdlib.h>

/*
remove the kth to the last element.
i.e.
0 - 1 - 2 - 4
remove 1th element
0 - 1 - 2
remove 0th element
0 - 1

etc.

the first method:
this will get the size then use size-1, this is inefficient because we iterate twice through the list. 

the second method:
this will iterate till k in one, then iterate to the end of k list and head, and the second list will owrk.

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
void removeKthMethodOne(struct node *,int);
void removeKthMethodTwo(struct node *,int);


int main(){
	struct node *ptr = initNode(0);
	for(int i = 1;i<10;i++){
		addNewNode(ptr,i);
	}
	printf("List: ");
	printList(ptr);
	
	printf("Remove 1th element: ");
	removeKthMethodOne(ptr,1); 
	printList(ptr);
	
	printf("Remove 3rd element: ");
	removeKthMethodTwo(ptr,3);
	printList(ptr);

	deleteList(ptr);
}

void removeKthMethodTwo(struct node * ptr,int k){
	struct node * temp = ptr;
	struct node * value = ptr;
	for(int i =0;i<k+1;i++)
		temp = temp->next;
	while(temp!=NULL){
		temp = temp->next;
		value = value->next;
	}
	deleteNode(ptr,value);
}

void removeKthMethodOne(struct node * ptr,int k){
	int size = 0;
	struct node * temp = ptr;
	while(temp != NULL){
		temp = temp -> next;
		size++;
	}
	size = size-k-1;
	int index = 0;
	temp = ptr;
	while(index != size){
		temp = temp->next;
		index++;
	}
	deleteNode(ptr,temp);
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
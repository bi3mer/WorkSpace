#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Check if the linked list is a palindrome.

- Colan
*/

typedef char* bool;
#define true "true"
#define false "false"

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
bool isPalindromeReverse(struct node *);
bool isPalindromeIterate(struct node *);

int main(){
	struct node *ptr = initNode(6);
	addNewNode(ptr,3);
	addNewNode(ptr,4);
	addNewNode(ptr,4);
	addNewNode(ptr,3);
	addNewNode(ptr,6);
	// 634436 is a palindrome.
	printList(ptr);
	printf("Is a palindrome reverse: %s\n",isPalindromeReverse(ptr));
	printf("Is a palindrome iterate: %s\n",isPalindromeIterate(ptr));
	addNewNode(ptr,7);
	printList(ptr);
	printf("Is a palindrome reverse: %s\n",isPalindromeReverse(ptr));
	printf("Is a palindrome iterate: %s\n",isPalindromeIterate(ptr));
}

bool isPalindromeIterate(struct node * ptr){
	// This method is best implemented with a stack, the theme is linked lists so I won't.
	struct node * fast  = ptr;
	struct node * slow  = ptr;
	struct node * stack = NULL;
	//get middle;
	while(fast!=NULL && fast->next!=NULL){
		if(stack == NULL)
			stack = initNode(slow->val);
		else {
			struct node * temp = initNode(slow->val);
			temp -> next = stack;
			stack = temp;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast!=NULL) 
		slow = slow->next; // odd size, so we move past it.
	while(slow!=NULL){
		if(slow->val != stack->val){
			return false;
		}
		slow  = slow->next;
		stack = stack->next;
	}
	return true;
}

bool isPalindromeReverse(struct node * ptr){
	// Create a reverse of the list and then check to see if both equal eachother
	if(ptr == NULL){
		return false;
	}
	struct node * reverse = initNode(ptr->val);
	struct node * iterate = ptr->next;
	while(iterate != NULL){
		struct node * temp = initNode(iterate->val);
		temp -> next = reverse;
		reverse = temp;
		iterate = iterate->next;
	}
	// Cycle through list now that reverse has been made
	while(ptr != NULL){
		if(ptr->val != reverse->val)
			return false;
		ptr = ptr->next;
		reverse = reverse->next;
	}
	return true;
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
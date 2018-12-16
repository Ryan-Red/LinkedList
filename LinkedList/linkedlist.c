#include <stdio.h>
#include <stdlib.h>

struct llnode {
	struct llnode* next;
	int val;
	struct llnode* previous;
};
typedef struct llnode llnode;

int addToHead(llnode **head, int val) {
	llnode *oldHead;
	if (head == NULL) { return -1;}
	oldHead = *head;
	*head = (llnode *)malloc(sizeof(llnode));
	(*head)->val = val;
	(*head)->previous = NULL;
	(*head)->next = oldHead;
	((*head)->next)->previous = *head;
	
	return 0;
}
int addToTail(llnode **head, int val) {
	llnode *newTail;
	if (head == NULL) { return -1; }
	if (*head == NULL) {
		*head = (llnode *)malloc(sizeof(llnode));
		(*head)->next = NULL;
		(*head)->previous = NULL;
		(*head)->val = val;
		return 0;
	}
	if ((*head)->next == NULL) {
		((*head)->next) = (llnode *)malloc(sizeof(llnode));
		((*head)->next)->val = val;
		((*head)->next)->next = NULL;
		((*head)->next)->previous = *head;
		return 0;
	}
	else {
		return addToTail(&((*head)->next), val);
	}


}
int llprint(llnode *head) {
	if (head == NULL) { return 0; }
	else {
		printf("%d\n", head->val);
		return (llprint(head->next));
	}
}
int main(void) {
	llnode* head = NULL;

	addToTail(&head, 15);
	addToHead(&head, 22);
	printf("Value at the first node is of: %d\n", head->val);
	printf("Tail value is of %d\n", (head->next)->val);
	llprint(head);
	return 0;


}
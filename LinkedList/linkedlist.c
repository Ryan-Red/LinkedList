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
	(*head)->val = val;
	(*head)->previous = NULL;
	(*head)->next = oldHead;
	((*head)->next)->previous = *head;
	return 0;
}
int main(void) {
	llnode* head = NULL;

	head = (llnode*) malloc(sizeof(llnode));
	addToHead(&head, 15);
	printf("Value at the first node is of: %d", head->val);
	return 0;


}
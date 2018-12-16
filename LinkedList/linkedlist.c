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
int addToTail(llnode **head, int val) {
	llnode *newTail;
	if (head == NULL) {
		printf("llnode not initialized");
		return -1;
	}
	if ((*head)->next != NULL) {
		return addToTail(&((*head)->next), val);
	}
	else {
		newTail = (llnode *)malloc(sizeof(llnode));
		newTail->val = val;
		newTail->next = NULL;
		newTail->previous = *head;
		(*head)->next = newTail;
		return 0;
	}

}
int main(void) {
	llnode* head = NULL;

	head = (llnode*)malloc(sizeof(llnode));
	addToHead(&head, 15);
	addToTail(&head, 22);
	printf("Value at the first node is of: %d", head->val);
	printf("Tail value is of %d", (head->next)->val);
	return 0;


}
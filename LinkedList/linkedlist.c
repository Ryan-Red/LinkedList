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
int llfree(llnode *head) {
	llnode *next = NULL;
	if (head == NULL) { return -1; }
	else {
		head->next = next;
		free(head);
		return llfree(next);
    }
}
int ll_del_from_tail(llnode **head) {
	if (head == NULL) { return -1; }
	
	if ((*head)->next != NULL) { return ll_del_from_tail(&((*head)->next)); }
	else {
		((*head)->previous)->next = NULL;
		free(*head);
	}
	return 0;
}
int ll_del_from_head(llnode **head) {
	llnode *next = NULL;
	if (head == NULL) { return -1; }

	((*head)->next)->previous = NULL;
	next = (*head)->next;
	free(*head);
	*head = next;
	return 0;
}

int main(void) {
	llnode* head = NULL;

	addToTail(&head, 15);
	addToHead(&head, 22);
	addToHead(&head, 35);
	addToTail(&head, 44);

	printf("Current list:\n");
	llprint(head);
	ll_del_from_head(&head);
	ll_del_from_tail(&head);

	printf("Shortened List:\n");
	llprint(head);

	llfree(head);

	return 0;


}
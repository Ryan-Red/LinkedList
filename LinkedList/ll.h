#include <stdio.h>
#include <stdlib.h>

struct llnode {
	struct llnode* next;
	int val;
	struct llnode* previous;
};

int ll_add_to_head(llnode **head, int val);
int ll_add_to_tail(llnode **head, int val);

int ll_del_from_head(llnode **head);
int ll_del_from_tail(llnode **head);

int llprint(llnode *head);
int llfree(llnode *head);

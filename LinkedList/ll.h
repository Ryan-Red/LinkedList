#include <stdio.h>
#include <stdlib.h>

struct llnode {
	struct llnode* next;
	int val;
	struct llnode* previous;
};
typedef struct llnode llnode;

int ll_add_to_head(llnode **head, int val);
int ll_add_to_tail(llnode **head, int val);

int ll_del_from_head(llnode **head);
int ll_del_from_tail(llnode **head);

int llprint(llnode *head);
int llfree(llnode *head);

int ll_find_by_val(llnode *head, int val);
int ll_del_by_val(llnode **head, int val);


int ll_insert_in_order(llnode **head, int val);

int ll_concat(llnode **strA, llnode **strB);

int ll_sort(llnode **head);
#include "ll.h"


int ll_add_to_head(llnode **head, int val) {
	llnode *oldHead;
	if (head == NULL) { return -1;}
	if (*head == NULL) {
		*head = (llnode *)malloc(sizeof(llnode));
		(*head)->next = NULL;
		(*head)->previous = NULL;
		(*head)->val = val;
		return 0;
	}

	oldHead = *head;
	*head = (llnode *)malloc(sizeof(llnode));
	(*head)->val = val;
	(*head)->previous = NULL;
	(*head)->next = oldHead;
	((*head)->next)->previous = *head;
	
	return 0;
}
int ll_add_to_tail(llnode **head, int val) {
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
		return ll_add_to_tail(&((*head)->next), val);
	}
}
int ll_print(llnode *head) {
	if (head == NULL) { return 0; }
	else {
		printf("%d\n", head->val);
		return (ll_print(head->next));
	}
}
int ll_print_bw(llnode *head) {
	llnode *node = NULL;

	node = head;
	while (1) {
		node = node->next;
		if (node->next == NULL) { break; }

	}
	while(1){
		printf("%d\n", node->val);
		node = node->previous;
		if (node == NULL) { break; }

	}
	return 0;
}
int ll_get_to_end(llnode **head) {
	if (head == NULL) { return -1; }

	if ((*head)->next != NULL) {
		return ll_get_to_end(&((*head)->next));
	}
	printf("%d\n", (*head)->val);
	return 0;

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
int ll_find_by_val(llnode *head, int val) {
	if (head == NULL) { return -1; }
	if (head->val != val) {
		if (head->next != NULL) { return ll_find_by_val(head->next, val); }
		else { return -1; }
	}else {
		return 1;
	}
}
int ll_del_by_val(llnode **head, int val) {
	llnode *node = NULL;
	if (head == NULL) { return -1; }
	
	printf("Currently tested value is: %d\n", (*head)->val);

	if ((*head)->val != val) {
		if ((*head)->next != NULL) { return ll_del_by_val(&((*head)->next), val); }
		else { return -1; }
	}else{
		if ((*head)->previous == NULL) { return ll_del_from_head(head); }
		else {
			node = (*head);
			*head = (*head)->next;
			(*head)->previous = node->previous;
			free(node);
			return 0;
		}
	}
}
int ll_insert_in_order(llnode **head, int val) {
	llnode *added = NULL;
	if (head == NULL) { return -1; }

	if (*head == NULL) {
		return ll_add_to_head(head, val);
	}

	if ((*head)->val <= val) {
		if ((*head)->next != NULL) { 
			return ll_insert_in_order(&((*head)->next), val);
		}
		else {
			return ll_add_to_tail(head, val);
		}
	}
	else {
		if ((*head)->previous != NULL) {
			added = (llnode *) malloc(sizeof(llnode));
			added->val = val;
			added->previous = (*head)->previous;
			added->next = *head;

			((*head)->previous)->next = added;
			(*head)->previous = added;
			return 0;

		}
		else {
			return ll_add_to_head(head, val);
		}
	}
}
int ll_concat(llnode **strA, llnode **strB) {
	if (strA == NULL) { return -1; }
	if (strB == NULL) { return -1; }

	if ((*strA)->next != NULL) {
		return ll_concat(&((*strA)->next), strB);
	}
	else {
		(*strA)->next = *strB;
		(*strB)->previous = (*strA);
		return 0;
	}
}
int ll_sort(llnode **head) {
	int temp, temp2,swap = 0;
	llnode *ptemp = NULL;

	if (head == NULL) { return -1; }

	while (1) {
		swap = 0;
		ptemp = (*head);

		while (ptemp->next != NULL) {	

			if (ptemp->val > (ptemp->next)->val) {
				temp = ptemp->val;
				temp2 = (ptemp->next)->val;

				ptemp->val = temp2;
				(ptemp->next)->val = temp;
				swap = 1;	
			}
			ptemp = ptemp->next;
		}
			if (swap == 0) { return 0; }
	
		
		
	}
	return 0;
}


int main(void) {
	llnode *head = NULL;
	llnode *tail = NULL;
	int i,r = 0;

	for (i = 0;i < 20;i++) {
		 ll_add_to_tail(&head, i * 37);
	}
	
	printf("Current list:\n");
	ll_print(head);

	ll_del_from_head(&head);
	ll_del_from_tail(&head);
	printf("Shortened List:\n");
	ll_print(head);

	printf("Value of 180 is found: %d (expected -1)\n", ll_find_by_val(head, 180));
	printf("Value of 629 is found: %d (expected 1)\n", ll_find_by_val(head, 629));

	r = ll_del_by_val(&head, 629);
	if (r == 0) { printf("629 has been found and deleted.\n"); }
	else if (r == -1) { printf("629 has not been found.\n"); }
	
	r = ll_del_by_val(&head, 180);
	if (r == 0) { printf("180 has been found and deleted.\n"); }
	else if (r == -1) { printf("180 has not been found.\n"); }

	printf("\n--------------------------------------------\n");
	printf("Insert In order, 190:\n");
	ll_insert_in_order(&head, 190);
	printf("Insert In order, 10:\n");
	ll_insert_in_order(&head, 10);
	printf("Insert In order, 1900:\n");
	ll_insert_in_order(&head, 1900);
	printf("Insert In order, 666:\n");
	ll_insert_in_order(&head, 666);

	printf("\nAll of Head:\n");
	ll_print(head);

	for (i = 0;i < 13;i++) {
		ll_insert_in_order(&tail, 10 * i);
	}

	printf("\nAll of Tail:\n");
	ll_print(tail);

	printf("\nConcatination:\n");
	ll_concat(&head, &tail);

	ll_print(head);

	printf("Sorting head:\n");
	ll_add_to_head(&head, 44);

	ll_sort(&head);
	ll_print(head);

	printf("Sorted List Backwards:\n");
	ll_print_bw(head);



	llfree(head);


	return 0;


}
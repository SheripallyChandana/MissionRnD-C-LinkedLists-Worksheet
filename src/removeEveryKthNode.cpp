/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int nodeCount = 0;
		
	if(head == NULL || K < 2)
		return NULL;
			
	struct node* temp = head;

	while(temp){

		++nodeCount;
		if(nodeCount == K - 1){
			if(temp->next != NULL)
				temp->next = temp->next->next;
			nodeCount = 0;		
		}
		temp = temp->next;		
	}	
	return head;
}
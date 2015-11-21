/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node* merge(struct node* firstHead, struct node* secondHead){
	
	struct node* result = NULL;
	
	if(firstHead == NULL)
		return secondHead;
	else if(secondHead == NULL)
		return firstHead;
	
	if(firstHead->num <= secondHead->num){		
		result = firstHead;
		result->next = merge(firstHead->next, secondHead);		
	}else{
		result = secondHead;
		result->next = merge(firstHead, secondHead->next);				
	}
	return result;
}		


void partition(struct node* source, struct node** left, struct node** right){

	struct node* curr;
	struct node* prev;
	if (source == NULL || source->next == NULL){
		*left = source;
		*right = NULL;
	}
	else{
		prev = source;
		curr = source->next;

		while (curr != NULL){
			curr = curr->next;
			if (curr != NULL){
				prev = prev->next;
				curr = curr->next;
			}
		}
		*left  = source;
		*right = prev->next;
		prev->next = NULL;
	}
}


struct node * sortLinkedList(struct node *head) {
	
	struct node* firstHead;
	struct node* secondHead;
	
	if(head == NULL || head->next == NULL)
		return head;

	partition(head, &firstHead, &secondHead);
	
	firstHead  = sortLinkedList(firstHead);
	secondHead = sortLinkedList(secondHead);
	
	return merge(firstHead, secondHead);
}
/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){

	int zeroCount = 0;
	int oneCount  = 0;
	int twoCount  = 0;
	
	struct node* temp = head;
	
	while(temp){
		
		if(temp->data == 0)
			++zeroCount;
		else if(temp->data == 1)
			++oneCount;
		else
			++twoCount;
		temp = temp->next;			
	}

	temp = head;
	
	while(zeroCount){
		temp->data = 0;
		--zeroCount;
		temp = temp->next;			
	}
	while(oneCount){
		temp->data = 1;
		--oneCount;
		temp = temp->next;			
	}
	while(twoCount){
		temp->data = 2;
		--twoCount;
		temp = temp->next;			
	}	
}
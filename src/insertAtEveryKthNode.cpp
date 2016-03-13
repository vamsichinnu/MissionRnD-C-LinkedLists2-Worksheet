/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *temp, *temp1 = NULL, *start;
	int count = 0;
	start = head;
	if (head&&K>0)
	{
		while (head != NULL)
		{
			count++;
			if (count != K)
			{
				head = head->next;

			}
			else
			{
				temp = head->next;
				temp1 = (struct node *)malloc(sizeof(struct node));
				temp1->num = K;
				head->next = temp1;
				temp1->next = temp;
				head = temp;
				count = 0;
			}
		}
		return start;
	}
	else
	{
		return NULL;
	}
}

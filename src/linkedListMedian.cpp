/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *ptr;
	if (head)
	{
		ptr = head;
		while (head->next != NULL)
		{
			if ((head->next)->next == NULL)
			{
				return ((ptr->num) + ((ptr->next)->num)) / 2;
			}
			ptr = ptr->next;

			head = (head->next)->next;
		}
		return ptr->num;
	}
	else
	{
		return -1;
	}
}

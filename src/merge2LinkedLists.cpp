/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp, *temp1, *res;
	if (head2&&head1)
	{
		res = (struct node *)malloc(sizeof(struct node) * 1);
		temp = (struct node *)malloc(sizeof(struct node) * 1);
		temp1 = (struct node *)malloc(sizeof(struct node) * 1);
		if (head1->num > head2->num)
		{
			temp = head1;
			head1 = head2;
			head2 = temp;
		}
		res = head1;
		while (head2 || head1)
		{

			if (head1&&head2)
			{
				if (head1->num <= head2->num)
				{

					temp = head1;
					head1 = head1->next;
				}
				else
				{
					temp1 = head2->next;
					head2->next = temp->next;
					temp->next = head2;
					head2 = temp1;
					temp = temp->next;
				}
			}
			else if (head1 == NULL&&head2)
			{
				temp->next = head2;
				break;
			}
			else if (head2 == NULL&&head1)
			{
				break;
			}
		}
		return res;
	}
	else if (head1 == NULL&&head2)
	{
		return head2;
	}
	else if (head2 == NULL&&head1)
	{
		return head1;
	}
	else
	{
		return NULL;
	}
}
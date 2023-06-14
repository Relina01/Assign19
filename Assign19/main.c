#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode
{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("%s\n", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main()
{
	char choose;
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	while(1)
	{
		pirntf("====== Menu ======\n");
		printf("n) next fruit\n");
		printf("p) previous fruit\n");
		printf("d) delete the current fruit\n");
		printf("i) insert fruit after current fruit\n");
		printf("o) output the fruit list(Output [0] at the end of the currently selected fruit)\n");
		printf("e) exit the program\n");
		printf("==================\n");
		printf("Select a menu : ");
		scanf_s("%c", &choose);

		if (choose == 'n')
		{
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		}
		else if (choose == 'p')
		{
			current = current->llink;
			if (current == head)
				current = current->llink;
		}
		else if (choose == 'd')
		{
			ddelete(head, head->rlink);
		}
		else if (choose == 'i')
		{
			printf("Enter the name of the fruit to add : ");
			ch = getchar();
			dinsert(head, ch);
		}
		else if (choose == 'o')
		{
			print_dlist(head);
		}
		else if (choose == 'e')
		{
			exit(1);
		}
		else
		{
			printf("Invalid menu\n\n");
			continue;
		}
		printf("\n\n");
	}
}
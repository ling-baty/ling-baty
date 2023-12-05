/***************************************
This file is for link list operation
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

#define LEN sizeof(LinkList)
//#define NAME_LEN 20

/*
struct projector 
{
	int channel;
	int frequency;
	char name[NAME_LEN];
	struct projector *ppronext;
};
*/

struct Node
{
	int value;
	struct Node* next; 
};
typedef struct Node LinkList;

//PRO *llcur, *llhead, *lltail;

/* create LinkList */
LinkList* createList(int n)
{
	assert(n != 0);

	int i;
	LinkList *head = NULL;
	LinkList *p = NULL;
	LinkList *pAhead = NULL;
	
	for (i = 0; i < n; i ++)
	{
		p = (LinkList *)malloc(LEN);
//		printf("Please input projector channel, frequency and name\n");
//		scanf("%d%d%s", &lltail->channel, &lltail->frequency, &lltail->name);	
		p->value = i;

		if (i == 0)
		{
			head = p;
			pAhead = head;
		}
		else
		{
			pAhead->next = p;
			pAhead = p;
		}
	}	
	p->next = NULL;
	
	return head;
}

/*insert node */
void insertNode(LinkList *head, int Kth, int value)
{
	assert(head != NULL);
	
	LinkList *p = NULL;
	LinkList *temp = NULL;
	p = head;
	
	while (Kth > 0)
	{
		if (p->next != NULL)
		{
			p = p->next;
			Kth --;	
		}
		else 
		{
			printf("Kth > the length of LinkList.");
			return;
		}
	}
	
	temp = (LinkList *)malloc(sizeof(LinkList));
	temp->value = value;
	temp->next = p->next;
	p->next = temp;
	return;
}

/* delete node */
void deleteNode(LinkList *head, int Kth)
{
	assert(head != NULL);
	
	LinkList *p = NULL;
	LinkList *temp = NULL; 
	
	p = head;
	while(Kth > 1)
	{
		if(p->next != NULL)
		{		 
			p = p->next; 
			Kth --;
		}	
		else
		{
			printf("Kth > the length of LinkList!\n");
			return;
		}
	}	
	temp = p->next;
	p->next = p->next->next;
	free(temp);
	return; 
}

LinkList * reverse(LinkList *head)
{
	assert(head != NULL);
	
	LinkList *p = head, *pnext = NULL;
	LinkList *temp = head;
	
	while(p->next != NULL)
	{
		if (p == head)
		{
			temp = p;
			p = p->next;
			head->next = NULL;		
		}
		else
		{
			pnext = p->next;
			p->next = temp;
			temp = p;
			p = pnext;
		}
		
	}
	p->next = temp;
	return p;
}

/*PRO *reverse(PRO *llhead1)
{
	PRO *llpre, *llnext, *llmid;
	
	lltail = llpre = llhead = llcur = llnext = llhead1;
	
	while( llcur -> ppronext != NULL)
	{
		llnext = llnext -> ppronext;
		if (llcur != llhead1)
			llcur -> ppronext = llpre;
		else
		{
			llpre -> ppronext = NULL;
			lltail = llpre;
			llmid = llnext;
		}
		llpre = llcur;
		llcur = llnext;
	}

	llcur -> ppronext = llpre;
	llhead = llcur;
	return llcur; 
}
*/

int main(void)
{
	int n = 5;
//	PRO *s1, *sret;
	LinkList *node = NULL, *sret;
	
	node = createList(n);
	sret = reverse(node);
	insertNode(node, 1, 1);
	deleteNode(node, 1); 
	return 0;	
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char data[100];
	struct Node *next;
}Node;

void add_(struct Node *target,char data[]);

int main()
{
	struct Node *head = malloc(sizeof(struct Node));
	
	head->next = NULL;
	
	struct Node *node1 = malloc(sizeof(struct Node));
	 
	
	
		
	add_(head,"sword");
	add_(head,"arrow");
	add_(head,"spear");
	
	struct Node *curr = head->next;
	while(curr != NULL)
	{
		printf("%s  ", curr->data);
		curr = curr->next;
	}
	
	curr = head->next;
	while(curr!=NULL)
	{
		struct Node *next = curr->next;
		free(curr);
		curr = next;
	}

/*	
while(1)
{
	int index;
	char dump;
	char i[100];

	


	printf("1: 추가 2: 제거 3: 정렬 4: 이동\n");
	printf("입력 : ");
	scanf("%d" , &index);
	scanf("%c" , &dump);
	
	if(index==1) add_(head,i);
	else if(index==2)	remove_();
	else if(index==3)	sort_();
	else if(index==4)	move_();
	else	printf("입력 오류입니다.\n");


}
	*/
	
	return 0;
}


void add_(struct Node *target,char data[])
{
		
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->next = target->next;
	strcpy(newNode->data,data);
	
	target->next = newNode;
	
	return;
}

void remove_(struct Node *target)
{
	struct Node *removeNode = target->next;
	target->next = removeNode->next;
	
	free(removeNode);
}



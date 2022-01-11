#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//링크드리스트 구조체 
typedef struct Node{
	char data[100];
	struct Node *next;
}Node;

void printNode_(struct Node *head);
void add_(struct Node *target,char data[]);		//노드 추가 함수 
void remove_(struct Node *target,char data[]);	//노드 삭제 함수 

int main()
{
	//메모리에 헤드 노드 추가
	struct Node *head = malloc(sizeof(struct Node));  
	head->next = NULL;
	strcpy(head->data,"인벤토리 :");
			
	add_(head,"sword");
	add_(head,"arrow");
	add_(head,"spear");
	
printNode_(head);

while(1)
{
	int index;
	char dump;
	char i[100];

	printf("1: 추가 2: 제거 3: 정렬 4: 이동\n");
	printf("입력 : ");
	scanf("%d" , &index);
	scanf("%c" , &dump);
	
	if(index==1) 
	{
		system("cls");
		printf("추가할 데이터 입력: ");
		gets(i);
		add_(head,i);
	}
	else if(index==2)
	{
		printf("제거할 데이터 입력: ");
		gets(i); 
		system("cls");
		remove_(head,i);
	}
	//else if(index==3)	sort_();
//	else if(index==4)	move_();
	else
	{
		system("cls");
		printf("입력 오류입니다.\n");
	}

	
printNode_(head);

}
	return 0;

}

void printNode_(struct Node *head)
{
	struct Node *curr = head->next;

	printf("%s" , head->data); 
	while(curr != NULL)
	{
		printf("%s  ", curr->data);
		curr = curr->next;
	}
	printf("\n\n"); 
	
}

void add_(struct Node *target,char data[])
{
	//target노드 뒤에 새 노드 추가
	struct Node *newNode = malloc(sizeof(struct Node));	
	newNode->next = target->next;	 
	strcpy(newNode->data,data);	//main으로부터 받은 data를 newNode의 data로 복사 
	target->next = newNode;
	
	return;
}

void remove_(struct Node *target,char data[])
{
	struct Node *curr = target;
	struct Node *removeNode;
	
	if(target->next == NULL)
	{
		printf("인벤토리에 삭제할 아이템이 없습니다.\n"); 
	}
	
	else 
	{
		while(curr->next != NULL)
		{
			if(!(strcmp(curr->next->data,data)))
			{
				printf("제거 실행\n");
				removeNode=curr->next;
				curr->next=curr->next->next;
				free(removeNode);
				return;
			}
			curr=curr->next;
		}
		if(curr->next==NULL)	printf("입력된 데이터와 일치하는 아이템이 없습니다.\n");
	
	}

	
	return;
}





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
void add_(struct Node *target,char data[]);	//노드 추가 함수 
void remove_(struct Node *target);			//노드 삭제 함수 
void sort_(struct Node *target);			//노드 정렬 함수 
void move_(struct Node *target);			//노드 이동 함수 
void swap_(struct Node *A,struct Node *B);

int main()
{
	//메모리에 헤드 노드 추가
	struct Node *head = malloc(sizeof(struct Node));  
	head->next = NULL;
			
	add_(head,"aaaa");
	add_(head,"bbbb");
	add_(head,"cccc");
	add_(head,"dddd");
	
printNode_(head);

	while(1)
	{
		int index;
		char dump;
		char i[100];
	
		printf("1: 추가 2: 제거 3: 정렬 4: 이동\n");
		printf("0: 종료\n");
		printf("입력 : ");
		scanf("%d" , &index);
		scanf("%c" , &dump);
		
		if(index==1) 
		{
			printf("추가할 데이터 입력: ");
			gets(i);
			add_(head,i);
		}
		else if(index==2)	remove_(head);
		else if(index==3)	sort_(head);
		else if(index==4)	move_(head);
		else if(index==0)	break;
		else
		{
			system("cls");
			printf("%d",index);
			printf("입력 오류입니다.\n");
		}
		
	printNode_(head);
	
	}
	//메모리 해제 
	struct Node *curr = head;
	while(curr !=NULL)
	{
		free(curr);
		curr=curr->next;
	}
	return 0;

}

void printNode_(struct Node *head)
{
	struct Node *curr = head->next;
	
	printf("인벤토리 : ");
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

void remove_(struct Node *target)
{
	struct Node *curr = target;
	struct Node *removeNode;
	
	char data[100];
	
	printf("제거할 데이터 입력: ");
	gets(data); 
	
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
		if(curr->next==NULL)	printf("인벤토리에 입력값과 일치하는 아이템이 없습니다.\n");
	
	}
	return;
}

void sort_(struct Node *target)
{
	int length,i,j,temp;
	struct Node *curr=target->next;
	struct Node *next=curr->next;
	for(length=1;curr->next!=NULL;curr=curr->next)	length++;	//리스트의 길이 측정 

	for(;length>0;length--)//버블 정렬 실행 
	{
		curr=target->next;
		next=curr->next;
		if(strcmp(curr->data,next->data)>0)		swap_(curr,next);
		for(temp=length-2;temp>0;temp--)
		{
			curr=curr->next;
			next=curr->next;
			if(next==NULL)	break; 
			if(strcmp(curr->data,next->data)>0)		swap_(curr,next);
		}
	}
	

	
	
	return; 
}
void move_(struct Node *target)
{
	struct Node *curr = target;
	struct Node *move1;
	struct Node *move2;
	
	char data1[100];
	char data2[100];
	
	printf("위치를 바꿀 첫번째 아이템 입력:");
	gets(data1);
	while(curr->next !=NULL)
	{
		if(!(strcmp(curr->next->data,data1)))
		{
			move1=curr->next;
		}
		curr=curr->next;
	}
	if((strcmp(move1->data,data1)))
	{
		printf("인벤토리에 일치하는 아이템이 없습니다.\n");
		return;
	}
	curr=target;
	printf("위치를 바꿀 두번째 아이템 입력:");
	gets(data2);
	while(curr->next !=NULL)
	{
		if(!(strcmp(curr->next->data,data2)))
		{
			move2=curr->next;
		}
		curr=curr->next;
	}
	if((strcmp(move2->data,data2)))
	{
		printf("인벤토리에 일치하는 아이템이 없습니다.\n");
		return;
	}
	
	swap_(move1,move2);
	
	return;
}

void swap_(struct Node *A,struct Node *B)
{
	char temp[100];
	strcpy(temp,A->data);
	strcpy(A->data,B->data);
	strcpy(B->data,temp);
	return;
}




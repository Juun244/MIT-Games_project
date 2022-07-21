#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//��ũ�帮��Ʈ ����ü 
typedef struct Node{
	char data[100];
	struct Node *next;
}Node;

void printNode_(struct Node *head);
void add_(struct Node *target,char data[]);	//��� �߰� �Լ� 
void remove_(struct Node *target);			//��� ���� �Լ� 
void sort_(struct Node *target);			//��� ���� �Լ� 
void move_(struct Node *target);			//��� �̵� �Լ� 
void swap_(struct Node *A,struct Node *B);

int main()
{
	//�޸𸮿� ��� ��� �߰�
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
	
		printf("1: �߰� 2: ���� 3: ���� 4: �̵�\n");
		printf("0: ����\n");
		printf("�Է� : ");
		scanf("%d" , &index);
		scanf("%c" , &dump);
		
		if(index==1) 
		{
			printf("�߰��� ������ �Է�: ");
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
			printf("�Է� �����Դϴ�.\n");
		}
		
	printNode_(head);
	
	}
	//�޸� ���� 
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
	
	printf("�κ��丮 : ");
	while(curr != NULL)
	{
		printf("%s  ", curr->data);
		curr = curr->next;
	}
	printf("\n\n"); 
	
}

void add_(struct Node *target,char data[])
{
	//target��� �ڿ� �� ��� �߰�
	struct Node *newNode = malloc(sizeof(struct Node));	
	newNode->next = target->next;	 
	strcpy(newNode->data,data);	//main���κ��� ���� data�� newNode�� data�� ���� 
	target->next = newNode;
	
	return;
}

void remove_(struct Node *target)
{
	struct Node *curr = target;
	struct Node *removeNode;
	
	char data[100];
	
	printf("������ ������ �Է�: ");
	gets(data); 
	
	if(target->next == NULL)
	{
		printf("�κ��丮�� ������ �������� �����ϴ�.\n"); 
	}
	
	else 
	{
		while(curr->next != NULL)
		{
			if(!(strcmp(curr->next->data,data)))
			{
				printf("���� ����\n");
				removeNode=curr->next;
				curr->next=curr->next->next;
				free(removeNode);
				return;
			}
			curr=curr->next;
		}
		if(curr->next==NULL)	printf("�κ��丮�� �Է°��� ��ġ�ϴ� �������� �����ϴ�.\n");
	
	}
	return;
}

void sort_(struct Node *target)
{
	int length,i,j,temp;
	struct Node *curr=target->next;
	struct Node *next=curr->next;
	for(length=1;curr->next!=NULL;curr=curr->next)	length++;	//����Ʈ�� ���� ���� 

	for(;length>0;length--)//���� ���� ���� 
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
	
	printf("��ġ�� �ٲ� ù��° ������ �Է�:");
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
		printf("�κ��丮�� ��ġ�ϴ� �������� �����ϴ�.\n");
		return;
	}
	curr=target;
	printf("��ġ�� �ٲ� �ι�° ������ �Է�:");
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
		printf("�κ��丮�� ��ġ�ϴ� �������� �����ϴ�.\n");
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




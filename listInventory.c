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
void add_(struct Node *target,char data[]);		//��� �߰� �Լ� 
void remove_(struct Node *target,char data[]);	//��� ���� �Լ� 

int main()
{
	//�޸𸮿� ��� ��� �߰�
	struct Node *head = malloc(sizeof(struct Node));  
	head->next = NULL;
	strcpy(head->data,"�κ��丮 :");
			
	add_(head,"sword");
	add_(head,"arrow");
	add_(head,"spear");
	
printNode_(head);

while(1)
{
	int index;
	char dump;
	char i[100];

	printf("1: �߰� 2: ���� 3: ���� 4: �̵�\n");
	printf("�Է� : ");
	scanf("%d" , &index);
	scanf("%c" , &dump);
	
	if(index==1) 
	{
		system("cls");
		printf("�߰��� ������ �Է�: ");
		gets(i);
		add_(head,i);
	}
	else if(index==2)
	{
		printf("������ ������ �Է�: ");
		gets(i); 
		system("cls");
		remove_(head,i);
	}
	//else if(index==3)	sort_();
//	else if(index==4)	move_();
	else
	{
		system("cls");
		printf("�Է� �����Դϴ�.\n");
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
	//target��� �ڿ� �� ��� �߰�
	struct Node *newNode = malloc(sizeof(struct Node));	
	newNode->next = target->next;	 
	strcpy(newNode->data,data);	//main���κ��� ���� data�� newNode�� data�� ���� 
	target->next = newNode;
	
	return;
}

void remove_(struct Node *target,char data[])
{
	struct Node *curr = target;
	struct Node *removeNode;
	
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
		if(curr->next==NULL)	printf("�Էµ� �����Ϳ� ��ġ�ϴ� �������� �����ϴ�.\n");
	
	}

	
	return;
}





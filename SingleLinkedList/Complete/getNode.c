#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; //Status�Ǻ���������,��ֵ�Ǻ������״̬����,��Ok��
typedef int ElemType; //ElemType��������ʵ���������,����Ϊint

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList; //����LinkList

Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); //����ͷ���,����Lָ����
	if(!(*L)) { //�洢�ռ����ʧ��
		return ERROR;
	} 
	(*L)->next = NULL;
	return OK;
}

//��ʼ����:˳���L�Ѿ�����  �������:����L������Ԫ�صĸ���
int ListLength(LinkList L) {
	int i = 0;
	LinkList p = L->next; //pָ���һ�����

	while(p) {
		//++i; һ��
		i++;
		p = p->next;
	}
	return i;
}

Status visit(ElemType c) {
	printf("%3d",c);
	return OK;
}

//��ʼ����:˳�����Ա�L�Ѵ���  �������:���ζ�L��ÿ������Ԫ�����
Status ListTraverse(LinkList L) {
	LinkList p = L->next;

	while(p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

Status getMidNode(LinkList L,ElemType *e) {
	LinkList search,mid;
	search = mid = L;

	while(search->next != NULL) {
		//search���ƶ��ٶ���mid������
		if(search->next->next != NULL) {
			search = search->next->next;
			mid = mid ->next;
		} else {
			search = search->next;
		}
	}
	*e = mid->data;
	return OK;
}

//�������n��Ԫ�ص�ֵ,������ͷ���ĵ������Ա�L(β�巨)
void CreateListTail(LinkList *L,int n) {
	LinkList p,r;
	int i;

	srand(time(0)); //��ʼ�����������
	*L = (LinkList)malloc(sizeof(Node));  //LΪ�������Ա�
	r = *L;  //rָ��β���Ľ��

	for(i=0;i<n;i++) {
		p = (Node*)malloc(sizeof(Node));  //�����½��
		p->data = rand()%100+1;  //�������100���ڵ�����
		r->next = p;  //����β�ն˽���ָ��ָ�������ɽ��
		r = p;  //����ǰ�����ɽ�㶨��Ϊ��β�ն˽��
	}
	r->next = NULL;  //��ǰ�������
  //r->next = p;
}

int main() {
	LinkList L;
	Status i;
	char opp;
	ElemType e;

	i=InitList(&L);
	printf("��ʼ��L��:ListLength(L)=%d\n",ListLength(L));

	printf("\n1.�鿴���� \n2.��������(β�巨) \n3.������ \n4.�м����ֵ \n0.�˳�  \n��ѡ����Ĳ���:\n");
	while(opp != '0') {
		scanf("%c",&opp);
		switch(opp) {
		case '1':
			ListTraverse(L);
			printf("\n");
			break;
		case '2':
			CreateListTail(&L,20);
			printf("���崴��L��Ԫ��(β�巨):\n");
			ListTraverse(L);
			printf("\n");
			break;
		case '3':
		  //ClearList(Phead); �������
			printf("ListLength(L)=%d\n",ListLength(L));
			printf("\n");
			break;
		case '4':
			getMidNode(L,&e);
			printf("�м����ֵ��:%d\n",e);
			printf("\n");
			break;
		case '0':
			exit(0);
		}
	}
}
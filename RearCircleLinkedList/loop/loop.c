#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef  int Status; // Status�Ǻ���������,����ֵ�ǽ��״̬��,��OK��
typedef  int ElemType; //ElemType�������������,������int����

typedef struct Node {
	ElemType data;
	struct Node *next;
}Node,*LinkList;

//��ʼ����ͷ���Ŀ�����
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); //����ͷ���,����Lָ���ͷ���
	if(!(*L)) {  //�洢����ʧ��
		return ERROR;
	}
	(*L)->next = NULL; 
	return OK;
}

//���Ա���
int ListLength(LinkList L) {
	LinkList p = L->next;
	int i = 0;
	
	while(p) {
		i++;
		p = p->next;
	}
	return i;
}

//�������n������ֵ,��β�巨�����л�����
void CreateListTail(LinkList *L,int n) {
	LinkList p,r;
	int i;

	srand(time(0));  //��ʼ�����������

	*L = (LinkList)malloc(sizeof(Node));  //LΪ������������
	r = *L;  //rΪָ��β����ָ��

	for(i = 0;i < n;i++) {
		p = (Node*)malloc(sizeof(Node));  //�����µĽ��
		p->data = rand()%100+1;  //�������100���ڵ���
		printf("%d  ",p->data);
		r->next = p; //����β�ն˽���ʼ��ָ�������ɵĽ��
		r = p; //����ǰ��㶨��Ϊ��β�ն˽��
	}
	r->next = (*L)->next->next;
}

//�������n������ֵ,��ͷ�巨�����޻�����
void CreateListHead(LinkList *L,int n) {
	LinkList p;
	int i;

	srand(time(0)); //��ʼ�����������

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;   //����һ����ͷ���ĵ�����

	for(i=0; i<n; i++) {
		p = (Node*)malloc(sizeof(Node));  //�����µĽ��
		p->data = rand()%100+1;  //�������100���ڵ���
		printf("%d  ",p->data);
		p->next = (*L)->next;  
		(*L)->next = p; //���뵽��ͷ
	}
}

//�Ƚϲ����ķ���
int HasLoop1(LinkList L) {
	LinkList cur1 = L; //����ָ��cur1
	int pos1 = 0; //cur1����

	while(cur1) {
		LinkList cur2 = L;
		int pos2 = 0;

		while(cur2) {
			if(cur2 == cur1) {  //cur1��cur2������ͬ���ʱ
				if(pos1 == pos2) {  //�߹�����һ��
					break;   //�޻�
				} else {
					printf("���ڵ�%d����㴦.\n\n",pos2);
					return 1;
				}
			}
			cur2 = cur2->next;  //����޻�,������һ�����
			pos2++;   
		}
		cur1 = cur1->next;  //cur1�������һ�����
		pos1++;
	}
	return 0;
}

//���ÿ���ָ�뷽��
int HasLoop2(LinkList L) {
	LinkList p = L;
	LinkList q = L;
	int step1 = 1;
	int step2 = 2;

	while(p != NULL && q != NULL && q->next != NULL) {
		p = p->next;
		if(q->next!=NULL) {
			q = q->next->next;
		}

		printf("p:%d,q:%d\n",p->data,q->data);

		if(p == q) {
			return 1;
		}
	}
	return 0;
}

void print(){
	printf("\n1.�����л�����(β�巨) \n2.�����޻�����(ͷ�巨) \n3.�ж������Ƿ��л� \n0.�˳� \n��ѡ����Ĳ���:");
}

int main() {
	LinkList L;
	char opp;
	Status i;
	int find;

	i= InitList(&L);
	printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
	
			
		print();
		do {
			scanf("%c",&opp);
			switch(opp) {
			case '1':
				printf("�����������:");
				scanf("%d",&find);
				CreateListTail(&L,find);
				printf("\n�ɹ������л�����L(β�巨)\n");
				printf("\n");
				print();
				break;
			case '2':
				printf("�����������:");
				scanf("%d",&find);
				CreateListHead(&L,find);
				printf("\n�ɹ������޻�����L(ͷ�巨)\n");
				printf("\n");
				print();
				break;
			case '3':
				printf("�Ƚϲ�����:\n\n");
				if(HasLoop1(L)) {
					printf("����:�����л�\n\n\n");
				} else {
					printf("����:�����޻�\n\n\n");
				}
				printf("����ָ�뷨:\n\n");
				if(HasLoop2(L)) {
					printf("����:�����л�\n\n\n");
				} else {
					printf("����:�����޻�\n\n\n");
				}
				printf("\n");
				print();
				break;
			case '0':
				exit(0);
			}
			
		}while(1);

	return 0;
}
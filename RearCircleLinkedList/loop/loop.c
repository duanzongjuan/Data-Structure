#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef  int Status; // Status是函数的类型,它的值是结果状态码,如OK等
typedef  int ElemType; //ElemType类型视情况而定,这里是int类型

typedef struct Node {
	ElemType data;
	struct Node *next;
}Node,*LinkList;

//初始化带头结点的空链表
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); //产生头结点,并用L指向此头结点
	if(!(*L)) {  //存储分配失败
		return ERROR;
	}
	(*L)->next = NULL; 
	return OK;
}

//线性表长度
int ListLength(LinkList L) {
	LinkList p = L->next;
	int i = 0;
	
	while(p) {
		i++;
		p = p->next;
	}
	return i;
}

//随机产生n个结点的值,用尾插法建立有环链表
void CreateListTail(LinkList *L,int n) {
	LinkList p,r;
	int i;

	srand(time(0));  //初始化随机数种子

	*L = (LinkList)malloc(sizeof(Node));  //L为整个线性链表
	r = *L;  //r为指向尾部的指针

	for(i = 0;i < n;i++) {
		p = (Node*)malloc(sizeof(Node));  //生成新的结点
		p->data = rand()%100+1;  //随机生成100以内的数
		printf("%d  ",p->data);
		r->next = p; //将表尾终端结点的始终指向新生成的结点
		r = p; //将当前结点定义为表尾终端结点
	}
	r->next = (*L)->next->next;
}

//随机产生n个结点的值,用头插法建立无环链表
void CreateListHead(LinkList *L,int n) {
	LinkList p;
	int i;

	srand(time(0)); //初始化随机数种子

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;   //建立一个带头结点的单链表

	for(i=0; i<n; i++) {
		p = (Node*)malloc(sizeof(Node));  //生成新的结点
		p->data = rand()%100+1;  //随机生成100以内的数
		printf("%d  ",p->data);
		p->next = (*L)->next;  
		(*L)->next = p; //插入到表头
	}
}

//比较步数的方法
int HasLoop1(LinkList L) {
	LinkList cur1 = L; //定义指针cur1
	int pos1 = 0; //cur1步数

	while(cur1) {
		LinkList cur2 = L;
		int pos2 = 0;

		while(cur2) {
			if(cur2 == cur1) {  //cur1与cur2到达相同结点时
				if(pos1 == pos2) {  //走过步数一样
					break;   //无环
				} else {
					printf("环在第%d个结点处.\n\n",pos2);
					return 1;
				}
			}
			cur2 = cur2->next;  //如果无环,继续下一个结点
			pos2++;   
		}
		cur1 = cur1->next;  //cur1继续向后一个结点
		pos1++;
	}
	return 0;
}

//利用快慢指针方法
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
	printf("\n1.创建有环链表(尾插法) \n2.创建无环链表(头插法) \n3.判断链表是否有环 \n0.退出 \n请选择你的操作:");
}

int main() {
	LinkList L;
	char opp;
	Status i;
	int find;

	i= InitList(&L);
	printf("初始化L后ListLength(L)=%d\n",ListLength(L));
	
			
		print();
		do {
			scanf("%c",&opp);
			switch(opp) {
			case '1':
				printf("请输入结点个数:");
				scanf("%d",&find);
				CreateListTail(&L,find);
				printf("\n成功创建有环链表L(尾插法)\n");
				printf("\n");
				print();
				break;
			case '2':
				printf("请输入结点个数:");
				scanf("%d",&find);
				CreateListHead(&L,find);
				printf("\n成功创建无环链表L(头插法)\n");
				printf("\n");
				print();
				break;
			case '3':
				printf("比较步数法:\n\n");
				if(HasLoop1(L)) {
					printf("结论:链表有环\n\n\n");
				} else {
					printf("结论:链表无环\n\n\n");
				}
				printf("快慢指针法:\n\n");
				if(HasLoop2(L)) {
					printf("结论:链表有环\n\n\n");
				} else {
					printf("结论:链表无环\n\n\n");
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
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; //Status是函数的类型,其值是函数结果状态代码,如Ok等
typedef int ElemType; //ElemType的类型视实际情况而定,这里为int

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList; //定义LinkList

Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); //产生头结点,并用L指向它
	if(!(*L)) { //存储空间分配失败
		return ERROR;
	} 
	(*L)->next = NULL;
	return OK;
}

//初始条件:顺序表L已经存在  操作结果:返回L中数据元素的个数
int ListLength(LinkList L) {
	int i = 0;
	LinkList p = L->next; //p指向第一个结点

	while(p) {
		//++i; 一样
		i++;
		p = p->next;
	}
	return i;
}

Status visit(ElemType c) {
	printf("%3d",c);
	return OK;
}

//初始条件:顺序线性表L已存在  操作结果:依次对L的每个数据元素输出
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
		//search的移动速度是mid的两倍
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

//随机产生n个元素的值,建立带头结点的单链线性表L(尾插法)
void CreateListTail(LinkList *L,int n) {
	LinkList p,r;
	int i;

	srand(time(0)); //初始化随机数种子
	*L = (LinkList)malloc(sizeof(Node));  //L为整个线性表
	r = *L;  //r指向尾部的结点

	for(i=0;i<n;i++) {
		p = (Node*)malloc(sizeof(Node));  //生成新结点
		p->data = rand()%100+1;  //随机生成100以内的数字
		r->next = p;  //将表尾终端结点的指针指向新生成结点
		r = p;  //将当前新生成结点定义为表尾终端结点
	}
	r->next = NULL;  //当前链表结束
  //r->next = p;
}

int main() {
	LinkList L;
	Status i;
	char opp;
	ElemType e;

	i=InitList(&L);
	printf("初始化L后:ListLength(L)=%d\n",ListLength(L));

	printf("\n1.查看链表 \n2.创建链表(尾插法) \n3.链表长度 \n4.中间结点的值 \n0.退出  \n请选择你的操作:\n");
	while(opp != '0') {
		scanf("%c",&opp);
		switch(opp) {
		case '1':
			ListTraverse(L);
			printf("\n");
			break;
		case '2':
			CreateListTail(&L,20);
			printf("整体创建L的元素(尾插法):\n");
			ListTraverse(L);
			printf("\n");
			break;
		case '3':
		  //ClearList(Phead); 清除链表
			printf("ListLength(L)=%d\n",ListLength(L));
			printf("\n");
			break;
		case '4':
			getMidNode(L,&e);
			printf("中间结点的值是:%d\n",e);
			printf("\n");
			break;
		case '0':
			exit(0);
		}
	}
}
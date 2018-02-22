#include<stdio.h>
#include<stdlib.h>

//链表存储结构体
typedef struct CLinkList {
	int data;
	struct CLinkList *next;
}node;

//初始化循环链表
void ds_init(node **pNode) {
	node *target;
	node *temp;
	int item;

	printf("请输入结点的,输入0初始化完成\n");
	
	while(1) {
		scanf("%d",&item);
		fflush(stdin);
		if(item == 0) {
			return;
		}

		if((*pNode) == NULL) {
			*pNode = (node*)malloc(sizeof(struct CLinkList));
			if(!(*pNode)) {
				exit(0);
			}
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		} else {
			for(target=(*pNode);target->next != (*pNode);target=target->next)
				;
			temp = (node*)malloc(sizeof(struct CLinkList));
			if(!temp) {
				exit(0);
			}
			temp->data = item;
			temp->next = *pNode;
			target->next = temp;
		}
	}
}

//遍历循环链表
void ds_traverse(node *pNode) {
	node *temp;
	temp = pNode;
	printf("******************链表中的元素*****************\n");
	do {
		printf("%4d",temp->data);
	}while((temp = temp->next) != pNode);
	printf("\n");
}

//插入结点
void ds_insert(node **pNode,int i) {
	node *target;
	node *temp;
	node *p;
	int item;
	int j=1;

	printf("请输入要插入的结点的值:");
	scanf("%d",&item);

	if(i == 1) {
		//新插入结点作为第一个结点
		temp = (node*)malloc(sizeof(struct CLinkList));
		if(!temp) {
			exit(0);
		}
		temp->data = item;
		//寻找最后一个结点
		for(target=(*pNode);target->next != (*pNode);target = target->next)
			;
		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;  //temp成为第一个结点,*pNode指向它
	} else {
		target = *pNode;
		for(;j<(i-1);++j) {
			target = target->next;
		}
		temp = (node*)malloc(sizeof(struct CLinkList));
		if(!temp) {
			exit(0);
		}
		temp->data = item;
		p = target->next;
		target->next = temp;
		temp->next = p;
	}
}

//删除结点
void ds_delete(node **pNode,int i) {
	node *target;
	node *p;
	int j = 1;

	if(i == 1) {
		//删除的是第一个结点,找到最后一个结点
		for(target=(*pNode);target->next !=(*pNode);target=target->next)
			;
		p = *pNode;
		*pNode = (*pNode)->next;
		target->next = *pNode;
		free(p);
	} else {
		target = *pNode;
		for(;j<(i-1);++j) {
			target = target->next;
		}
		p = target->next;
		target->next = p->next;
		free(p);
	}
}

//返回所在结点的位置
int ds_search(node *pNode,int elem) {
	int i = 1
		;
	node *target;

	for(target=pNode;target->data != elem && target->next != pNode;++i) {
		target = target->next;
	}
	if(target->next == pNode) { //表中不存在该元素
		return 0;
	} else {
		return i;
	}
}

int main() {
	char opp;
	node *pHead = NULL;
	int find;

	printf("\n1.初始化链表 \n2.遍历链表 \n3.插入结点 \n4.删除结点 \n5.返回元素位置 \n0.退出 \n请选择你要进行的操作:");
	while(opp != '0') {
		scanf("%c",&opp);
		switch(opp) {
		case '1':
			ds_init(&pHead);
			printf("\n");
			ds_traverse(pHead);
			break;
		case '2':
			ds_traverse(pHead);
			printf("\n");
			break;
		case '3':
			printf("请输入要插入结点的位置:");
			scanf("%d",&find);
			ds_insert(&pHead,find);
			printf("在位置%d插入值后:\n",find);
			ds_traverse(pHead);
			printf("\n");
			break;
		case '4':
			printf("请输入要删除结点的位置:");
			scanf("%d",&find);
			ds_delete(&pHead,find);
			printf("在位置%d删除值后:\n",find);
			ds_traverse(pHead);
			break;
		case '5':
			printf("请输入你要查找的结点值:");
			scanf("%d",&find);
			printf("%d元素所在位置:%d\n",find,ds_search(pHead,find));
			printf("\n");
			break;
		case '0':
			exit(0);
		}
	}
	return 0;
}
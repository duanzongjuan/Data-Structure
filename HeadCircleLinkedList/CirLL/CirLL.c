#include<stdio.h>
#include<stdlib.h>

//����洢�ṹ��
typedef struct CLinkList {
	int data;
	struct CLinkList *next;
}node;

//��ʼ��ѭ������
void ds_init(node **pNode) {
	node *target;
	node *temp;
	int item;

	printf("���������,����0��ʼ�����\n");
	
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

//����ѭ������
void ds_traverse(node *pNode) {
	node *temp;
	temp = pNode;
	printf("******************�����е�Ԫ��*****************\n");
	do {
		printf("%4d",temp->data);
	}while((temp = temp->next) != pNode);
	printf("\n");
}

//������
void ds_insert(node **pNode,int i) {
	node *target;
	node *temp;
	node *p;
	int item;
	int j=1;

	printf("������Ҫ����Ľ���ֵ:");
	scanf("%d",&item);

	if(i == 1) {
		//�²�������Ϊ��һ�����
		temp = (node*)malloc(sizeof(struct CLinkList));
		if(!temp) {
			exit(0);
		}
		temp->data = item;
		//Ѱ�����һ�����
		for(target=(*pNode);target->next != (*pNode);target = target->next)
			;
		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;  //temp��Ϊ��һ�����,*pNodeָ����
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

//ɾ�����
void ds_delete(node **pNode,int i) {
	node *target;
	node *p;
	int j = 1;

	if(i == 1) {
		//ɾ�����ǵ�һ�����,�ҵ����һ�����
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

//�������ڽ���λ��
int ds_search(node *pNode,int elem) {
	int i = 1
		;
	node *target;

	for(target=pNode;target->data != elem && target->next != pNode;++i) {
		target = target->next;
	}
	if(target->next == pNode) { //���в����ڸ�Ԫ��
		return 0;
	} else {
		return i;
	}
}

int main() {
	char opp;
	node *pHead = NULL;
	int find;

	printf("\n1.��ʼ������ \n2.�������� \n3.������ \n4.ɾ����� \n5.����Ԫ��λ�� \n0.�˳� \n��ѡ����Ҫ���еĲ���:");
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
			printf("������Ҫ�������λ��:");
			scanf("%d",&find);
			ds_insert(&pHead,find);
			printf("��λ��%d����ֵ��:\n",find);
			ds_traverse(pHead);
			printf("\n");
			break;
		case '4':
			printf("������Ҫɾ������λ��:");
			scanf("%d",&find);
			ds_delete(&pHead,find);
			printf("��λ��%dɾ��ֵ��:\n",find);
			ds_traverse(pHead);
			break;
		case '5':
			printf("��������Ҫ���ҵĽ��ֵ:");
			scanf("%d",&find);
			printf("%dԪ������λ��:%d\n",find,ds_search(pHead,find));
			printf("\n");
			break;
		case '0':
			exit(0);
		}
	}
	return 0;
}
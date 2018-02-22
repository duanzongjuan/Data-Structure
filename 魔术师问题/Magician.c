/**
*ħ��ʦ����һ�����е�13�ź��ƣ�Ԥ�Ƚ������źú������һ��
*���泯�¡��Թ���˵�����Ҳ����ƣ�ֻ�����Ϳ��Բµ�ÿ������ʲô��
*�Ҵ��������������������ţ��ֳ���ʾ����ħ��ʦ�����������������Ϊ1��
*���������������Ǻ���A��������A���������ϣ��ڶ�����1,2��
*����һ���Ʒ�����Щ�Ƶ����棬���ڶ����Ʒ������������Ǻ���2��
*Ҳ���������������������ν��н�13����ȫ��������׼ȷ����
*���⣺�ƵĿ�ʼ˳������ΰ��ŵģ�
**/

#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct node {
	int data;
	struct node *next;
}SqList,*LinkList;

LinkList CreateListTail() {
	LinkList head = NULL;
	LinkList r,s;
	int i;

	r = head;

	for(i=1; i<=CardNumber; i++) {
		s = (LinkList)malloc(sizeof(SqList));
		s->data = 0;

		if(head == NULL) {
			head = s;
		} else {
			r->next = s;
		}
		r = s;
	}
	r->next = head;

	return head;
}

void magician(LinkList head) {
	LinkList p;
	int j;
	int CountNumber = 2;

	p = head;
	p->data = 1;

	while(1) {
		for(j=0;j<CountNumber;j++) {
			p = p->next;
			if(p->data != 0) {  //��λ�����ƵĻ�,����һ��λ�ã�˵���Ѿ����ó�ȥ��
				p = p->next;
				j--;
			}
		}
		if(p->data == 0) {
			p->data = CountNumber;
			CountNumber++;
			if(CountNumber == 14) {
				break;
			}
		}
	}
}

main() {
	LinkList p;
	int i;

	p = CreateListTail();
	magician(p);

	for(i=0;i<CardNumber;i++) {
		printf("����%d  ",p->data);
		p = p->next;
	}
	printf("\n");
}
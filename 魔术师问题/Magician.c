/**
*魔术师利用一副牌中的13张黑牌，预先将他们排好后叠放在一起，
*牌面朝下。对观众说：“我不看牌，只数数就可以猜到每张牌是什么，
*我大声数数，你们听，不信？现场演示。”魔术师将最上面的那张牌数为1，
*把他翻过来正好是黑桃A，将黑桃A放在桌子上，第二次数1,2，
*将第一张牌放在这些牌的下面，将第二张牌翻过来，正好是黑桃2，
*也将它放在桌子上这样依次进行将13张牌全部翻出，准确无误。
*问题：牌的开始顺序是如何安排的？
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
			if(p->data != 0) {  //该位置有牌的话,则下一个位置，说明已经被拿出去了
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
		printf("黑桃%d  ",p->data);
		p = p->next;
	}
	printf("\n");
}
//����洢�ṹ�Ķ���
typedef struct CLinkList {
	int data;
	struct CLinkList *next;
}node;

//������
void ds_insert(node **pNode,int i) {
	node *target;
	node *temp;
	node *p;
	int item;
	int j = 1;

	printf("������Ҫ�������ֵ:");
	scanf("%d",&item);
	
	if(i == 1) {
		//�²�������Ϊ��һ�����
		temp = (node*)malloc(sizeof(struct CLinkList));
		if(!temp) {
			exit(0);
		}
		temp->data = item;
		//Ѱ�����һ�����
		for(target=(*pNode);target->next != (*pNode);target=target->next)
			;
		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp; //�²������Ϊ��һ�����
	} else {
		target = *pNode;
		for(;j<(i-1);++j) {
			target=target->next;
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
//��ʼ��ѭ������
void ds_init(node **pNode) {

	int item;
	node *temp;
	node *target;
	printf("���������ֵ,����0��ʾ��ɳ�ʼ��\n");
	while(1) {
		scanf("%d",&item);
		fflush(stdin);
		if(item == 0) {
			return;
		}

		if((*pNode == null)) {
			//ѭ��������ֻ��һ�����,һ��ʼ*pNodeָ��Ϊ��,����ռ�,*pNodeָ�����Ŀռ�,�Ժ󶼲�ִ��
			*pNode = (node*)malloc(sizeof(struct CLinkList));
			if(!(*pNode)) {
				exit(0);
			}
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		} else {
			//*pNode��Ϊ��,�������ɺ������
			for(target=(*pNode);target->next!=(*pNode);target=target->next) {
				//������һ���½��
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
//初始化循环链表
void ds_init(node **pNode) {

	int item;
	node *temp;
	node *target;
	printf("请输入结点的值,输入0表示完成初始化\n");
	while(1) {
		scanf("%d",&item);
		fflush(stdin);
		if(item == 0) {
			return;
		}

		if((*pNode == null)) {
			//循环链表中只有一个结点,一开始*pNode指向为空,申请空间,*pNode指向分配的空间,以后都不执行
			*pNode = (node*)malloc(sizeof(struct CLinkList));
			if(!(*pNode)) {
				exit(0);
			}
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		} else {
			//*pNode不为空,依次生成后续结点
			for(target=(*pNode);target->next!=(*pNode);target=target->next) {
				//生成下一个新结点
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
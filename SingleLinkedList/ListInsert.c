/**
*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)
*�������:��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ���+1
**/

Status ListInsert(LinkList *L,int i,ElemType e) {

	int j;
	LinkList p,s;
	
	j = 1;
	p = *L;

	while(p && j < i) {  //����Ѱ�ҵ�i�����
		p = p->next;
		j++;
	}

	if(!p || j > i) {
		return ERROR;
	} 

	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	s->next = p->next;
	p->next = s;

	return OK;
}
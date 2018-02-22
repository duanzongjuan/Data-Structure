/**
*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L);
*�������:ɾ��L�ĵ�i������Ԫ��,����e������ֵ,����-1;
**/

Status(LinkList *L,int i,ElemType *e) {

	int j;
	LinkList p,q;

	j = 1;
	p = *L;

	while(p->next && j < i) {
		p = p->next;
		++j;
	}

	if(!(p->next) || j > i) {
		return ERROR;
	}

	q = p->next;
	p->next = q->next;

	*e = q->data;
	free(q);

	return OK;
}
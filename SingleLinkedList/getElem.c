/**
*��ʼ����:˳�����Ա�L����, 1<=i<=ListLength(L)
*�������:��e����L�е�i��λ�õ�ֵ
**/

Status getElem(LinkList L,int i,ElemType *e) {
	int j;
	LinkList p;

	j = 1;
	p = L->next;

	while(p && j < i) {
		p = p->next;
		++ j;
	}

	if(!p || j > i) {
		return ERROR;
	}

	*e = p->data;
	return OK;
}
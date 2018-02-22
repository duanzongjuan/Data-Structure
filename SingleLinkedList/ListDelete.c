/**
*初始条件:顺序线性表L已存在,1<=i<=ListLength(L);
*操作结果:删除L的第i个数据元素,并用e返回其值,长度-1;
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
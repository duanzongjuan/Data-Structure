/**
*初始条件:顺序线性表L存在, 1<=i<=ListLength(L)
*操作结果:用e返回L中第i个位置的值
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
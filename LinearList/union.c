//La表示A集合,Lb表示B集合
void union(List *La, List Lb) {
	int La_len,Lb_len,i;
	ElemType e;

	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);

	for(i=1;i<Lb_len;i++) {
		getElem(Lb,i,&e);
		if(!LocateElem(*La,e)) {
			ListInsert(La,++La_len,e);
		}
	}
}
Status getMidNOde(LinkList L,ElemType *e) {

	LinkList search,mid;
	search = mid = L;

	while(search->next != NULL) {
		//search���ƶ��ٶ���mid������
		if(search->next->next != NULL) {
			search = search->next->next;
			mid = mid->next;
		} else {
			search = search->next;
		}
	}
	
	*e = mid->data;
	return OK;
}
//β�巨����������
void CreateListTail(LinkList *L,int n) {
	LinkList p,r;
	int i;
	
	srand(time(0)); //��ʼ�����������
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for(i=0;i<n;i++) {
		p = (Node*)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p; //r����ƶ�
	}
	r->next = NULL;
}
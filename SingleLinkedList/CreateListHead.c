//ͷ�巨����������
/**
*���������ı�ָ��L��ֵ,�������������ú󱣴�L��ֵ,�Ǿ�Ҫ��LinkList *L,
*����,�������ݵľ���ָ��ĵ�ַ,�������ú�,��Ȼ�Ϳ���ȥ�ı�ָ���ֵ;
*���������ֻ���޸�ָ����ָ�������,���������ָ���ֵ,��ô��LinkList L;
**/

void CreateListHead(LinkList *L,int n) {

	LinkList p;
	int i;
	
	srand(time(0)); //��ʼ�����������

	*L = (LinkList)malloc(sizeof(Node));  //��ʼ������,��������ʱ,L��ָ��һ���յ�����,����ı�ָ���ֵ,����Ҫ��*L
	(*L)->next = NULL;

	for(i=0; i<n; i++) {
		p = (LinkList)malloc(sizeof(Node)); //�����½��
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
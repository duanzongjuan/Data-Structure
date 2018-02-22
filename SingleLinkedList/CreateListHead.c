//头插法建立单链表
/**
*如果函数会改变指针L的值,而函数结束调用后保存L的值,那就要用LinkList *L,
*这样,向函数传递的就是指针的地址,结束调用后,自然就可以去改变指针的值;
*而如果函数只会修改指针所指向的内容,而不会更改指针的值,那么用LinkList L;
**/

void CreateListHead(LinkList *L,int n) {

	LinkList p;
	int i;
	
	srand(time(0)); //初始化随机数种子

	*L = (LinkList)malloc(sizeof(Node));  //初始化链表,函数调用时,L会指向一个空的链表,即会改变指针的值,所以要用*L
	(*L)->next = NULL;

	for(i=0; i<n; i++) {
		p = (LinkList)malloc(sizeof(Node)); //生成新结点
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
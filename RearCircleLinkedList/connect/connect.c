/**
*实现将两个线性表（a1，a2，…，an）和（b1，b2，…，bm）连接成一个线性表（a1，…，an，b1，…bm）的运算
*
**/

//假设A,B为非空循环链表的尾指针
LinkList connect(LinkList A,LinkList B) {
	LinkList p = A->next;  //保存A表的头结点位置
	A->next = B->next->next; //B表的开始结点链接到A表尾
	free(B->next); //释放B的头结点
	B->next = p;
	return B; //返回新循环链表的尾指针
}
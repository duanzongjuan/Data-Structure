/**
*ʵ�ֽ��������Ա�a1��a2������an���ͣ�b1��b2������bm�����ӳ�һ�����Ա�a1������an��b1����bm��������
*
**/

//����A,BΪ�ǿ�ѭ�������βָ��
LinkList connect(LinkList A,LinkList B) {
	LinkList p = A->next;  //����A���ͷ���λ��
	A->next = B->next->next; //B��Ŀ�ʼ������ӵ�A��β
	free(B->next); //�ͷ�B��ͷ���
	B->next = p;
	return B; //������ѭ�������βָ��
}
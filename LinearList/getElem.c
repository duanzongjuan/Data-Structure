#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

/**
*Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��
*��ʼ����:���Ա�L�Ѿ�����,�� 1 <= i <= L->ListLength(L)
*�������:��e����L�е�i������Ԫ�ص�ֵ
**/

Status getElem(SqList L, int i, ElemType *e) {
	if(L.length == 0 || i > L.length) {
		return ERROR;
	}
	*e = L.data[i-1];
	return OK;
}
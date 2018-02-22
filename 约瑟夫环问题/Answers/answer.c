/**
*���Ϊ1��N��N���˰�˳ʱ�뷽��Χ��һȦ��ÿ�˳���һ�����루�������������������룩��
*��ʼ��ѡһ����������Ϊ��������ֵM���ӵ�һ���˰�˳ʱ�뷽����1��ʼ˳������
*����Mʱֹͣ��������M���˳��У�������������Ϊ�µ�Mֵ,
*����˳ʱ�뷽���ϵ���һ���˿�ʼ��1�����������ȥ��ֱ��������ȫ������Ϊֹ
**/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE_NUM 100
#define TRUE 1U
#define FALSE 0U

typedef struct NodeType {
	int id;
	int cipher;
	struct NodeType *next;
}NodeType;

static void CreaList(NodeType **ppHead,const int n) {
	NodeType *pNew,*pCur;
	int i;
	int iCipher;

	for(i=1;i<=n;i++) {
		printf("�������%d���˵�����",i);
		scanf("%d",&iCipher);
		pNew = GetNode(i,iCipher);
		if(*ppHead == NULL) {
			*ppHead = pCur = pNew;
			pCur->next = *ppHead;
		} else {
			pNew->next = pCur->next;
			pCur->next = pNew;
			pCur = pNew;
		}
	}
	printf("��ɵ�����Ĵ���!\n");
}

static NodeType *GetNode(const int iId,const int iCipher) {
	NodeType *pNew;

	pNew = (NodeType*)malloc(sizeof(NodeType));
	if(!pNew) {
		printf("Error,the memory is not enough!\n");
		exit(-1);
	}
	pNew->id = iId;
	pNew->cipher = iCipher;
	pNew->next = NULL;
	return pNew;
}

static void PrntList(const NodeType *pHead) {
	const NodeType *pCur = pHead;
	if(EmptyList(pHead)) {
		return;
	}
	do {
		printf("��%d����,����:%d\n",pCur->id,pCur->cipher);
		pCur = pCur->next;
	} while(pCur != pHead);
	getchar();
}

static unsigned EmptyList(const NodeType *pHead) {
	if(!pHead) {
		printf("The list is empty!\n");
		return TRUE;
	}
	return FALSE;
}

static void StatGame(NodeType **ppHead,int iCipher) {
	int iCounter;
	NodeType *pCur,*pDel,*pPrv;
	int iFlag = 1;

	pPrv = pCur = *ppHead;
	while(pPrv->next != *ppHead) {
		pPrv = pPrv->next;
	}
	while (iFlag) {
		for(iCounter=1;iCounter<iCipher;iCounter++) {
			pPrv = pCur;
			pCur = pCur->next;
		}
		if(pPrv == pCur) {
			iFlag = 0;
		}
		pDel = pCur;
		pPrv->next = pCur->next;
		pCur = pCur->next;
		iCipher = pDel->cipher;
		printf("��%d���˳���,����:%d",pDel->id,pDel->cipher);
		free(pDel);
	}
	*ppHead = NULL;
	getchar();
}

main() {
	int n,m;
	NodeType *pHead = NULL;
	while(1) {
		printf("������������(����������%d)",MAX_NODE_NUM);
		scanf("%d",&n);
		printf("������ÿ���˵ĳ�ʼ����:");
		scanf("%d",&m);
		if(n > MAX_NODE_NUM) {
			printf("������������%d\n",MAX_NODE_NUM);
			continue;
		} else {
			break;
		}
	}
	CreaList(&pHead,n);
	printf("\n-----------ѭ������ԭʼ��ӡ------------\n");
	PrntList(pHead);
	printf("\n-----------ɾ�����������ӡ------------\n");
	StatGame(&pHead,m);
}
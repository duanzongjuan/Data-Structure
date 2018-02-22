/**
*编号为1～N的N个人按顺时针方向围坐一圈，每人持有一个密码（正整数，可以自由输入），
*开始人选一个正整数作为报数上限值M，从第一个人按顺时针方向自1开始顺序报数，
*报道M时停止报数。报M的人出列，将他的密码作为新的M值,
*从他顺时针方向上的下一个人开始从1报数，如此下去，直至所有人全部出列为止
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
		printf("请输入第%d个人的密码",i);
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
	printf("完成单链表的创建!\n");
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
		printf("第%d个人,密码:%d\n",pCur->id,pCur->cipher);
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
		printf("第%d个人出列,密码:%d",pDel->id,pDel->cipher);
		free(pDel);
	}
	*ppHead = NULL;
	getchar();
}

main() {
	int n,m;
	NodeType *pHead = NULL;
	while(1) {
		printf("请输入总人数(人数不超过%d)",MAX_NODE_NUM);
		scanf("%d",&n);
		printf("请输入每个人的初始密码:");
		scanf("%d",&m);
		if(n > MAX_NODE_NUM) {
			printf("输入人数超过%d\n",MAX_NODE_NUM);
			continue;
		} else {
			break;
		}
	}
	CreaList(&pHead,n);
	printf("\n-----------循环链表原始打印------------\n");
	PrntList(pHead);
	printf("\n-----------删除出队情况打印------------\n");
	StatGame(&pHead,m);
}
#define MAXSIZE 20
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE]; 
	int length; //线性表当前长度
}SqList;
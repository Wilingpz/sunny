typedef struct List//结构体可以包含它的指针但是不可以包含它的变量
//包含其指针形成树或链表
{
	int data;
	struct List * next;
}List;
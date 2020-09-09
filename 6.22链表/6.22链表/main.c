#include "SList.h"
void listtest()
{
	SList test;

	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 4);
	SListPushFront(&test, 6);
	SListPushFront(&test, 9);
	SListPrint(&test);
	SListPopFront(&test);
	SListDestory(&test);

}
int main()
{
	listtest();
	return 0;
}
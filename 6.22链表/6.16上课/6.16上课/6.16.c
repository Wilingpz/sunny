void LoadData(MailList *ml)//加载函数
{
	FILE *fp = fopen("dizhi", "rb");
	while (fread(&ml->data[ml->size], sizeof(Student), 1, fp))//每次都读
		//一条数据，返回值为0则数据读完了，为1则读取了该条数据
	{
		ml->size++;
		if (ml->size >= ml->capacity)
		{
			IncCapacity(ml);
		}
	}
	fclose(fp);
	fp = NULL;
}
//预处理命令
//#define 宏定义  N宏名  --预处理命令提前编译
#define N 10k

int main()
{
	int n = N;//int n = 10k;有问题；去掉k则可以运行
	return 0;
}
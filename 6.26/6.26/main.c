# include <stdio.h>
# include <stdlib.h>
//# pragma pack(1)
//# pragma pack(2)   //设置默认对齐数为2
//# pragma pack(4)
//# pragma pack(8)
//# pragma pack(16)
struct s1              //结构体
{
	char c1;      //默认对齐数是8   对比4，选4 则3*4=12
	int i;		 //设置对齐数为1， 1+4+1=6
	char c2;	 //设置对齐数为2，2+4+2=8
};
struct s2
{
	char c1;	// 2*4=8
	char c2;//设置对齐数为1， 1+1+4=6
	int i;	//设置对齐数为2，2+4=6
};
struct s3
{
	double c1;	//8*2=16
	char c2;//设置对齐数为1， 8+1+4=13
	int i;	//设置对齐数为2，8+2+4=14
};
//#pragma pack()  //取消设置的默认对齐数，还原为默认设置
struct s4
{
	char c1;      //struct s3的对齐数为8，则整体对齐数为8，8+16+8=32
	struct s3 s3;//设置对齐数为1， 1+13+8=22
	double d;	 //设置对齐数为2，2+14+8=24
};
struct s5
{
	struct s4 s4;	//同s4，32+3*8=56
	int e;//设置对齐数为1， 22+4+5+4+4=39
	char f[5];//设置对齐数为2，24+4+6+4+4=42
	char* h;
	void(*g)(int);  //空类型指针函数

};
int main()
{
	printf("s1=%d\n", sizeof(struct s1));    //输出结构体大小
	printf("s2=%d\n", sizeof(struct s2));
	printf("s3=%d\n", sizeof(struct s3));
	printf("s4=%d\n", sizeof(struct s4));
	printf("s5=%d\n", sizeof(struct s5));
	system("pause");
	return 0;
}

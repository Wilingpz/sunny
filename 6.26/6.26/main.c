# include <stdio.h>
# include <stdlib.h>
//# pragma pack(1)
//# pragma pack(2)   //����Ĭ�϶�����Ϊ2
//# pragma pack(4)
//# pragma pack(8)
//# pragma pack(16)
struct s1              //�ṹ��
{
	char c1;      //Ĭ�϶�������8   �Ա�4��ѡ4 ��3*4=12
	int i;		 //���ö�����Ϊ1�� 1+4+1=6
	char c2;	 //���ö�����Ϊ2��2+4+2=8
};
struct s2
{
	char c1;	// 2*4=8
	char c2;//���ö�����Ϊ1�� 1+1+4=6
	int i;	//���ö�����Ϊ2��2+4=6
};
struct s3
{
	double c1;	//8*2=16
	char c2;//���ö�����Ϊ1�� 8+1+4=13
	int i;	//���ö�����Ϊ2��8+2+4=14
};
//#pragma pack()  //ȡ�����õ�Ĭ�϶���������ԭΪĬ������
struct s4
{
	char c1;      //struct s3�Ķ�����Ϊ8�������������Ϊ8��8+16+8=32
	struct s3 s3;//���ö�����Ϊ1�� 1+13+8=22
	double d;	 //���ö�����Ϊ2��2+14+8=24
};
struct s5
{
	struct s4 s4;	//ͬs4��32+3*8=56
	int e;//���ö�����Ϊ1�� 22+4+5+4+4=39
	char f[5];//���ö�����Ϊ2��24+4+6+4+4=42
	char* h;
	void(*g)(int);  //������ָ�뺯��

};
int main()
{
	printf("s1=%d\n", sizeof(struct s1));    //����ṹ���С
	printf("s2=%d\n", sizeof(struct s2));
	printf("s3=%d\n", sizeof(struct s3));
	printf("s4=%d\n", sizeof(struct s4));
	printf("s5=%d\n", sizeof(struct s5));
	system("pause");
	return 0;
}

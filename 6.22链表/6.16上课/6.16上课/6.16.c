void LoadData(MailList *ml)//���غ���
{
	FILE *fp = fopen("dizhi", "rb");
	while (fread(&ml->data[ml->size], sizeof(Student), 1, fp))//ÿ�ζ���
		//һ�����ݣ�����ֵΪ0�����ݶ����ˣ�Ϊ1���ȡ�˸�������
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
//Ԥ��������
//#define �궨��  N����  --Ԥ����������ǰ����
#define N 10k

int main()
{
	int n = N;//int n = 10k;�����⣻ȥ��k���������
	return 0;
}
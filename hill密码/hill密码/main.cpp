#include <iostream>
#include <string>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>

using namespace std;

 //����һЩ������
 const int M = 26;   //���弯��{a,b,...,z}��26��Ӣ����ĸ

 //�к��о�Ϊ5
 const int ROW = 5;
 const int COL = 5;

 //����5*5�ļ��ܾ���
 int K[ROW][COL];

 //����5*5�Ľ��ܾ���
 int D[ROW][COL];

 int P[ROW];  //���ĵ�Ԫ
 int C[ROW];  //���ĵ�Ԫ
 int F[ROW];  //���Ľ��ܺ�ĵ�Ԫ

 //��Ԫ��gcd(a,b) = ax + by = d
 struct GCD
 {
     int x;
     int y;
     int d;
 };
class Hill_Cipher
  {
    public:
//�����������
     void random_Matrix();
//����������ʽ
     int Det(int matrix[ROW][ROW], int row);
//�������������Լ��
     int gcd(int a, int b);
     /*
     *�жϾ���K�Ƿ���ģ26������¿���
	 *��Ϊ������ģ26�������´��ڿ������ĳ�ֱ�Ҫ������
	 *gcd(det K,26) = 1
	 */
	 bool Inverse(int matrix[ROW][ROW]);
	 //�������
	 void multiphy(int matrix[ROW][ROW], int p[ROW], int row);
	 //����������
     void adjoint_matrix(int matrix[ROW][ROW], int row);
	 //�����ļ���Ϊ����
	 string encryption(string plaintext);
	//�����Ľ���Ϊ����(Ϊ�˱�ʶ���,����ͳһ��Сд��ĸ��Ϊ����,��д��ĸ��Ϊ����)
	 string deciphering(string ciphertext);
	 //ŷ������㷨��ģ����
	 GCD extended_Euclid(int a, int b);
	 //ģ������
	 int inverse(int a, int m);
	 //����C++�����ڸ���ȡģ�����ú���,�����Լ��趨һ��
	 //����һ��ģM��ֵ
	 int Mod(int a);
		};
  void Hill_Cipher::random_Matrix()
{
	     int i, j;
	     for (i = 0; i < ROW; i++)
		     {
              for (j = 0; j < COL; j++)
	         {
		             K[i][j] = rand() % 26;  //����һ��5*5ģ26�ľ���
		         }
		     }
		 }
 //����������ʽ
int Hill_Cipher::Det(int matrix[ROW][ROW], int row)
{
	 int i, j;
     int cofa[ROW][ROW];            //���ڴ��������
	 int l;   //lΪ���ݹ�����������
     int p = 0, q = 0;
     int sum = 0;
     //�����к�����ͬ(����),��������ʽ��ֵһ������,�ʲ���Ҫ�ж��Ƿ�Ϊ����
	 //�ݹ��
	   if (row == 1)        
		   return matrix[0][0];
       for (i = 0; i < row; i++)
	    {
		      for (l = 0; l < row - 1; l++)
			      {
			        if (l < i)
				            p = 0;
			         else
				            p = 1;
			       for (j = 0; j< row - 1; j++)
				        {
				          cofa[l][j] = matrix[l + p][j + 1];
				        }
			     }
		     //�൱��(-1)^i
			      if (i % 2 == 0)
			          q = 1;
		     else
			          q = (-1);
	     sum = sum + matrix[i][0] * q * Det(cofa, row - 1);
    }
       return sum;
    }

 //�������������Լ��
 int Hill_Cipher::gcd(int a, int b)
{
    int temp;
    //�����������Ĵ�С,ʹ��aΪ�ϴ���
     if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
while (a % b)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
return b;
 }

 /*
	  *�жϾ���K�Ƿ���ģ26������¿���
	  *��Ϊ������ģ26�������´��ڿ������ĳ�ֱ�Ҫ������
	  *gcd(det K,26) = 1
	  */
	 bool Hill_Cipher::Inverse(int matrix[ROW][ROW])
	 {
    if (gcd(Det(matrix, ROW), M) == 1)
         return true;
    else
         return false;
}
	 void Hill_Cipher::multiphy(int matrix[ROW][ROW], int p[ROW], int row)
	 {
		 int i, j;
		 //�Ƚ����ĵ�Ԫ����
		 memset(C, 0, sizeof(C));
		 for (i = 0; i < ROW; i++)
		 {
			 for (j = 0; j < ROW; j++)
			 {
				 C[i] += P[j] * K[j][i];
			 }
		 }
	 }

 //�����ļ���Ϊ����
 string Hill_Cipher::encryption(string plaintext)
 {
 int i;
 string ciphertext;
 //���ַ���ת��Ϊ��������
     for (i = 0; i < ROW; i++)
     {
         P[i] = plaintext[i] - 'a';
     }
 multiphy(K, P, ROW);
 //����������ת��Ϊ����
    for (i = 0; i < ROW; i++)
        //�����Ƚ���ģ26,�ٷ���Ϊ��Ӧ����ĸ
    {
        C[i] = Mod(C[i]);
        ciphertext += C[i] + 'A';
    }
     return ciphertext;
}

//����������
void Hill_Cipher::adjoint_matrix(int matrix[ROW][ROW], int row)
{
    int i, j, k, l;
    int p, q;
    p = q = 0;
    int temp[ROW][ROW];
    for (i = 0; i < ROW; i++)
{
    for (j = 0; j < ROW; j++)
        {
            for (k = 0; k < ROW - 1; k++)
  {
      if (k < i)
              p = 0;
      else
              p = 1;
      for (l = 0; l < ROW - 1; l++)
          {
           if (l < j)
             q = 0;
             else
              q = 1;
             temp[k][l] = matrix[k + p][l + q];
          }
     }
      D[j][i] = (int)pow(-1, (double)i + j)*Det(temp, ROW - 1);
      D[j][i] = Mod(D[j][i]);
  }
 } 
}

//�����Ľ���Ϊ����(Ϊ�˱�ʶ���,����ͳһ��Сд��ĸ��Ϊ����,��д��ĸ��Ϊ����)
string Hill_Cipher::deciphering(string ciphertext)
{
 //����������
 string text;
 int determinant = Det(K, ROW);
 int inver = inverse(determinant, 26);
 adjoint_matrix(K, ROW);   //�������
 cout << "����ʽ��ֵ: " << determinant << endl;
 int i, j;
 memset(F, 0, sizeof(F));
 for (i = 0; i < ROW; i++)
 {
     for (j = 0; j < ROW; j++)
         {
             F[i] += C[j] * D[j][i];
         }
     F[i] *= inver;
     F[i] = Mod(F[i]);   //�㵽�Ľ��Ҫģȥ26
 }
 for (i = 0; i < ROW; i++)
    text += F[i] + 'a';
 return text;
 }

GCD Hill_Cipher::extended_Euclid(int a, int b)
{
 GCD aa, bb;
 if (b == 0)
  {
      aa.x = 1;
	         aa.y = 0;
	         aa.d = a;
	         return aa;
	     }
 else
     {
         bb = extended_Euclid(b, a%b);
         aa.x = bb.y;
         aa.y = bb.x - (a / b) * bb.y;
         aa.d = bb.d;
     }
 return aa;
}
 int Hill_Cipher::inverse(int a, int m)
 {
     GCD aa;
     aa = extended_Euclid(a, m);
     return aa.x;
}

int Hill_Cipher::Mod(int a)
{
 return a >= 0 ? a % M : (M + a % M);
 }
 int main()
 {
 int i, j;
 Hill_Cipher hh;
 cout << "ʹ��ϣ�����������Ϣ�ļӽ���:" << endl;
 
     //srand()��������һ���Ե�ǰʱ�俪ʼ���������.�Ա�֤ÿ�β�������������󶼲���ͬ
     srand((unsigned)time(0));
 hh.random_Matrix();
 while (!hh.Inverse(K))
     {
         hh.random_Matrix();
     }
 cout << "�������5*5�ľ���:" << endl;
 for (i = 0; i < ROW; i++)
     {
      for (j = 0; j < COL; j++)     
	 {
       printf("%2d  ", K[i][j]);
     }
         cout << endl;
     }
cout << "�þ���ģ26����,��˿�����Ϊ��Կ." << endl;
cout << endl;

    //������ѡ��Կ���Ը�����5Ԫ������Ϣ���мӽ���
    string plaintext, ciphertext;
cout << "������5Ԫ������Ϣ:" << endl;
cin >> plaintext;
ciphertext = hh.encryption(plaintext);
cout << endl;
cout << "������ͨ��ϣ�����뷨���ܹ���,�����������ϢΪ:" << endl;
cout << ciphertext << endl;
cout << endl;

    cout << "***����0:�˳�          ***" << endl;
cout << "***����1:�鿴���Ŀռ��***" << endl;
cout << "***����2:�鿴���Ŀռ��***" << endl;
cout << "***����3:�鿴��Կ      ***" << endl;
cout << "***����4:����Ϣ����    ***" << endl;
cout << "***����5:�鿴�˵�      ***" << endl;

    char c;
while (cin >> c)
{
    if (c == '0')
{
cout << endl;
         cout << "�˳�" << endl;
         break;
     }
   else if (c == '1')
     {
         cout << "���Ŀռ�:" << endl;
         for (i = 0; i < ROW; i++)
                 cout << P[i] << "  ";
         cout << endl;
         cout << endl;
     }
    else if (c == '2')
     {
         cout << "���Ŀռ�:" << endl;
         for (i = 0; i < ROW; i++)
                 cout << C[i] << "  ";
         cout << endl;
         cout << endl;
     }
   else if (c == '3')
     {
  cout << "��Կ:" << endl;
  for (i = 0; i < ROW; i++)
      {
          for (j = 0; j < ROW; j++)
	                 {
	                     printf("%2d  ", K[i][j]);
	                 }
	             cout << endl;
	         }
	     cout << endl;
	 }
  else if (c == '4')
   {
       hh.adjoint_matrix(K, ROW);
       string ss;
       ss = hh.deciphering(ciphertext);
       cout << "�����Ľ��ܹ���,��ʾ��ԭ����������Ϣ:" << endl;
       cout << ss << endl;
       cout << endl;
   }
  else
   {
       cout << "***����0:�˳�          ***" << endl;
       cout << "***����1:�鿴���Ŀռ��***" << endl;
       cout << "***����2:�鿴���Ŀռ��***" << endl;
       cout << "***����3:�鿴��Կ      ***" << endl;
       cout << "***����4:����Ϣ����    ***" << endl;
       cout << "***����5:�鿴�˵�      ***" << endl;
   }
     }
        return 0;
}
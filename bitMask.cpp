//2nd program by Piskunov Yury MMF IT 19

#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;


int main()
{
	setlocale(LC_ALL,"Ru");
	int a=123;
	int mask=1;
	int rez=1;
	int size=sizeof(a)*8;

	int i;
	int temp=a;
	for (i=1;i<=size;i++)
	{
		rez=temp&mask;// ������ ��� ����� ����� ������� ���������� �� 1, ����� ����� ��������� ���,
		temp=temp>>1;//����� ���������� ������ �� 1, ����� ��� � ��������� ���� ����� ��������� ���
		cout<<setw(2)<<i<<"-�� ��� ����� "<<a<<" ����� "<<rez<<endl;
	}

	cout<<"----------------------"<<endl;

	temp=a;//����� �� ���������
	for (i=size;i>=1;i--) //����� �������� �������� ����� ����� ������� (����� ���� 100000, ����� 010000 � �.�.)
	{            mask=(1<<(i-1));
	rez=(temp&mask)>>(i-1);// ����������� �����, ���������� ��� ������� ����� �������, ����� ����� ���������� ������ �� ������ ������� �������
	//			 (���� ��������, 00100 - ����� 00001 - ����� ����� �������� �� 8, � 1 (��� �������� �������))

	cout<<setw(2)<<i<<"-�� ��� ����� "<<a<<" ����� "<<rez<<endl;
	}


	cout<<"----------------------"<<endl;
	temp=a;
	for (i=1;i<=size;i++)
	{
		rez=temp&mask;
		mask=mask<<1;
		cout<<setw(2)<<i<<"-�� ��� ����� "<<a<<" ����� "<<(rez!=0)<<endl;
	}

	int v=1;
	cin>>v;
	return 0;
}
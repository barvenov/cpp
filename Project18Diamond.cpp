//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
//#include <cmath>

using namespace std;

void offsetSpaces(int n)
{
	for(int k=0;k<n;k++)// ������� ��������� �������, ����� ������ ���������
		cout<<' ';
}

void triangleEquilateralBorderByStars(int a, int b)
{
	bool noChange=true;
	
	for(int i=0;i<=b;i++) //������ ����������� ������� � b ����� (� ����������� ��������)
	{
		if(noChange)//��������� ���������� ����� ����������� �� ��������� (����� ���� ���)
		{
			offsetSpaces(b-i/2);
			if(i==0)
				cout<<'*';//      *******  - ������������� ������ ��������� ������, �.�. ������ �		
			else
			{					
				cout<<'*';
				for(int k=0; k<i-1; k++)
					cout<<' ';
				cout<<'*';						
			}
			cout<<'\n';
		}
		else cout<<"\n";
		noChange=!noChange;
	}
}

void triangleEquilateralBorderByStarsInversed(int a, int b)
{
	bool noChange=true;
	
	for(int i=b-2;i>=0;i--) //������ ����������� ������� � b ����� (� ����������� ��������)
	{
		if(noChange)//��������� ���������� ����� ����������� �� ��������� (����� ���� ���)
		{
			offsetSpaces(b-i/2);
			if(i==0)
				cout<<'*';//      *******  - ������������� ������ ��������� ������, �.�. ������ �		
			else
			{					
				cout<<'*';
				for(int k=0; k<i-2; k++)
					cout<<' ';
				if(i-2>0) cout<<'*';						
			}
			cout<<'\n';
		}
		else cout<<"\n";
		noChange=!noChange;
	}
}

void printDiamond(int a, int b)
{
	triangleEquilateralBorderByStars(a, b);
	triangleEquilateralBorderByStarsInversed(a, b);
}

void dialogPrintDiamond()
{
	int a=0;
	int b=0;

	cout<<"\nEnter a horizontal diagonal a of a diamond (an odd integer): ";
	while(a%2==0) cin>>a;
	cout<<"\nEnter a vertical diagonal b of a diamond (an odd integer): ";
	while(b%2==0)	cin>>b;
	cout<<'\n';
	
	printDiamond(a, b);
}


int main()
{
	setlocale(LC_ALL, "Ru");

	//triangleByBucks();
	dialogPrintDiamond();


	int v=1;
	cin>>v;
	return 0;
}

/**********
++++ ������ � ����������� a � b
#��9 �� 20/10##
��������� ��� ������������ � ����� ��� ������� (http://kvodo.ru/urok-10-formatirovannyiy-vvod-vyivod-v-c.html)
**********/
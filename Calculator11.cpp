//2nd program by Piskunov Yury MMF IT 19

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	char operation = -1;
	double a = 0;
	double b = 0;
	double rez=0;
	int i=1;	

	cout << "\nEnter operands divided by any of following operation + - * / % (enter = for result)";
	cin >> rez;
	
	while (true)
	{

		if(i==1)
		{
			a=rez;				
			cin>>operation;
			i++;
		}
		if(i==2&&operation!='=') cin >> b;
		if(operation=='/'&&b==0)
		{
			while(b==0)
			{
				cout<<"\nZero is not allowed to use as a divisor - enter another one: ";
				cin>>b;
			}
		}
		i=1;

		switch (operation)
		{
		case '+': rez=a+b;
			break;
		case '-': rez=a-b;
			break;
		case '*': rez=a*b;
			break;
		case '/': rez=a/b;
			break;
		case '%': if(a- (int)a==0&&b- (int)b==0) rez=(int)a%(int)b;
				  else {cout<<"This operation is appliable only to integer operands"; rez=a;}
				  break;
		case '=': cout<<rez;
			break;
		//case 'c': break;

		default:
			{
				cout << "Wrong operation";
				break;
			}
		}
	}


	int v = 1;
	cin >> v;
	return 0;
}

/**********
##��6 �� 13/10##

����������� �� switch . ����������� ������� �����������. ������������ ������ �����, ����� �������� � ���� �������
(�+�, �-�, �*�, �/�, '%' � �.�.), ����� ������ �����. ������� ��������� ��������.

"����������" �����������. ��������� �������� ������� �� 0. ��������� ���������� �������� ��� ������� ��������.
���� ������ �������� ������ ������ �c�, �� ����������� ������������ � ������, ��� ����� ������� �q� ������ ��������
����������� ��������� ������ (quit).   

"�����������" ����������� (�� �����) ������������ ����� ������� ������������ ���������� ����� � �������� (���������),
����� �������� ������� �=� ������� �������� ���������, � ����������� ������������ � ������.  
********/
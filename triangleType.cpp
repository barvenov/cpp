//2nd program by Piskunov Yury MMF IT 19

#include <iostream>
#include <clocale>

using namespace std;

float m=0,n=0,p=0;


void variablesInput()
{
	cout<<"Enter lengths of sides\n";
	cin>>m;
	cin>>n;
	cin>>p;
}


int main()
{
	setlocale(LC_ALL, "Ru");

	variablesInput();


	//test of existance-->sort by ascending then sum first two - if sum>max then true
	//���� �� ������������� ������������ � ������������ ����������� ���������� �������
	//����� �� ����� ���������� �������, ��� ����� ������ �������� � � ������ ���� ���������� �������

	float temp=0;

	//after this sorting p equals maximal side
	while(true)
	{
		if(m>n)
		{
			temp=n;
			n=m;
			m=temp;
		}
		if(n>p)
		{
			temp=p;
			p=n;
			n=temp;
		}

		if((m+n)<=p)
		{
			cout<<"\nTringle with such sides doesn't exist - enter another one:\n";
			variablesInput();			
		}
		else break;
	}
	
	
	cout<<"\n\n\n";
	
	// p contains the biggest side - so we search for a type of the angle opposite to it
	// � �������� ���������� ������� - ������� �� ���� ������� ���� ������ �������� ���� �������
	float cosinusP=(m*m+n*n-p*p)/(2*m*n); // ����� ��� ���������� ������������ (���� float), ������� � �������� ��� ���������
	// �� ���� �� ���������, ���� ���� �� ���� ���� ������������ ���������� � ��� ���� ��������� ������� �� � ������������


	if(cosinusP)//���� ������� �� ����� ����, �� 2 �������� - ���� ���� ������, ���� �����:
		if(cosinusP>0) cout<<"\nThe triangle is acute-angled\n";//�������������
		else cout<<"\nThe triangle is obtuse\n";//������������
	else cout<<"\nThe triangle is right\n";//������������� (����� �������� �������, � ������� ������� ����� ����)

	if(m==p&&m==n&&n==p) cout<<"\nThe triangle is equilateral\n";//��������������
	else if(m==p||m==n||n==p) cout<<"\nThe triangle is isosceles\n";//��������������




	int v=1;
	cin>>v;
	return 0;
}
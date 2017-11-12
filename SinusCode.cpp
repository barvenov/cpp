//program by Piskunov Yury MMF IT 19 10102017

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

#pragma region sinus
double degreesToRadians(int degrees)
{
	double pi=3.14159265358979232;
	return degrees/180.0*pi;
}

double sinus(double radians, double precision)
{
	double z=radians; // ������� ����
	double previousZ=0;
	double rez=z;
	float i=1;
	//long int j=0;

	while(abs(abs(z)-previousZ)-precision>0)//(j<1000000)//���������� ���� ��������� �� ����� ���� �� ������ �������
	{
		previousZ=abs(z);
		i++;
		z*=-radians*radians/i/(i+1);
		rez+=z;
		//j++;
	}

	return rez;
}

void sinusInputOutput()
{
	int angle=0;
	double precision=10;

	cout<<"\n������� ���� ���������� ������ � ���� ������ ����� ��������\n";
	cin>>angle;
	while(precision>angle/10.0||precision>=1)
	{
		cout<<"������� ��������� �������� ���������� ������ ������� ���� ������ 1/10 ���������, �� �� ������� 1\n";
		cin>>precision;
	}

	cout<<"�������� ������ "<<sinus(degreesToRadians(angle), precision)<<'\n';
}
#pragma endregion

#pragma region exponentaPowered
double expPower(double power, double precision)
{
	double z=1; // ������� ����
	double previousZ=0;
	double rez=z;
	float i=0;
	//long int j=0;

	while(previousZ-z-precision>0||i<3)//(j<1000000)//���������� ���� ��������� �� ����� ���� �� ������ �������
	{
		previousZ=z;
		i++;
		z*=power/i;
		rez+=z;
		//j++;
	}

	return rez;
}

void expPowerInputOutput()
{
	int power=0;
	double precision=-1;

	cout<<"\n������� ����� �������, � ������� �� ������ �������� ����������\n";
	cin>>power;
	while(precision<=0)
	{
		cout<<"������� ��������� �������� ����������\n";
		cin>>precision;
	}

	cout<<"�������� ���������� � ������� "<<power<<" ����� "<<expPower(power, precision)<<'\n';
}
#pragma endregion

#pragma region Fibonacci
int funcFibonacci(int n)
{
	int z=1;
	int previousZ=0;
	int temp=0;
	int i=1;
	
	while(i<n)
	{
		temp=z;
		z+=previousZ;
		previousZ=temp;
		i++;
	}

	return z;
}

void funcFibonacciInputOutput()
{
	int n=0;
	
	while(n<=0)
	{
		cout<<"\n������� ����� ����� �� ���� ��������� (������� ����)\n";
		cin>>n;
	}

	cout<<"�������� "<<n<<"-�� ����� ���� ���������� ����� "<<funcFibonacci(n)<<'\n';
}
#pragma endregion

int main()
{
	setlocale(LC_ALL, "Ru");

	funcFibonacciInputOutput();
	expPowerInputOutput();
	sinusInputOutput();
	
	int v=1;
	cin>>v;
	return 0;
}



/*

�������� �������, ����������� ����� �� ���� �������.
��������� f(x) (������������������ ����������) �� ������������ ������� �� ��� ��� ���� ��������� ���� �� ������ ������ �������.
��� �������� �������� ������ ������ ���� ������ �������. ���������� �������� ���� ���� ���� �� ������ ������ ������� 
��������� ������� ���� ���� �� � ���� ������ �� ���� ��������� �� �������, ������ ��� ��� �������� � � ��������� ���������
��� ���������� � ��� ����� ��������. ���� ���������� ������� - ������ ��������� ���� ����� ����� ���� �������� �� �����������
� ������� ����� ���� �������� ��������� - �������� �� � � ���������, �� i � �����������.

*/
//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <ctime>

#define _USE_MATH_DEFINES

using namespace std;

double funcTab(double x)
{
	return sin(x)/x;
}

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


int funcFibonacciRecurs(int a)
{	
	if(a==1) return 1;
	if(a==2) return 2;
	return a+funcFibonacciRecurs(a-1);
}

void funcFibonacciInputOutput()
{
	int n=0;

	while(n<=0)
	{
		cout<<"\n������� ����� ����� �� ���� ��������� (������� ����)\n";
		cin>>n;
	}

	cout<<"�������� "<<n<<"-�� ����� ���� ���������� ����� "<<funcFibonacciRecurs(n)<<'\n';
}


void tabulating()
{

	double a=-1, b=-a;
	double h=0.01;

	for(double x=a; x<=b; x=x+h)
	{
		cout<<"\n x= "<<setw(5)<<x<<", y= "<<setw(5)<<funcTab(x);
	}


}

int gcDivisor(int a, int b)//Euclid's algorithm
{
	int gcd=0;
	int max=b, min=a;

	if(a>b)
	{
		max=a;
		min=b;
	}

	int remainder=-1;
	while(remainder!=0)
	{
		gcd=remainder;
		remainder=max%min;
		max=min;
		min=remainder;
	}

	return gcd;
}

void gcDivisorDialog()
{
	int a=0, b=0;

	char q=0;
	while(q!='q')
	{
		while(a<=0||b<=0||a==b)
		{
			cout<<"\n������� ��� ������������� �������� ���� ����� �����, ��� ������� ��������� �����: \n";
			cin>>a;
			cin>>b;
		}

		cout<<"\n��� ����� "<<a<<" � "<<b<<" �����: "<<gcDivisor(a, b)<<'\n';
		a=0;

		cout<<"��� ������ ������� q - ����� ������ ������, ����� ����������: ";
		cin>>q;
	}
}

bool isPrime(int n)
{
	if(n==5||n==2) return true;

	int lastDigit=n%10;	
	if(lastDigit==0||lastDigit%2==0||lastDigit==5) return false;

	int k=sqrt(n)+1;

	for(int i=3; i<=k; i=i+2)
		if(n%i==0) return false;

	return true;
}

void factorization(int a)//naive way
{
	int i=0, f=2;

	//f=2 need
	for(;a>1;i++)
		if(a%f==0) a/=f;
		else break;
		if(i) cout<<"\nThe number has a factor "<<f<<" in a power of "<<i;


		for(f=3, i=0; a>1; f=f+2, i=0)
		{
			if(isPrime(f))
			{
				for(;;i++)
					if(a%f==0) a/=f;				
					else break;
					if(i) cout<<"\nThe number has a factor "<<f<<" in a power of "<<i;
			}
			else continue;//not required
		}		
}

void factorizationDialog()
{
	int a=0;

	char q=0;
	while(q!='q')
	{
		while(a<=2)
		{
			cout<<"\n������� ������������� ����� ������� 2, ������� ��������� �������������: \n";
			cin>>a;			
		}

		factorization(a);
		a=0;

		cout<<"\n��� ������ ������� q - ����� ������ ������, ����� ����������: ";
		cin>>q;
	}
}

/*void dialogPrimeOrNot()
{
int n=0;

cout<<"\nEnter an integer number more than 1 to check if it is prime: ";
while(n<2)
{
cin>>n;
cout<<'\n';
}
if(isPrime(n)) cout<<"\n The number "<<n<<" is prime.";
else cout<<"\n The number "<<n<<" is not prime.";
}*/

int randXor(int max)
{
	int a=21, b=35, c=4, tmp=time(NULL);
	tmp^=tmp<<a;
	tmp^=tmp>>b;
	tmp^=tmp<<c;
	tmp%=max;
	return tmp>0?tmp:-tmp;
}

void randDialog()
{
	int a=0;

	char q=0;
	while(q!='q')
	{
		while(a<=0)
		{
			cout<<"\n������� ������������� ����� ������� 0, ��� ������� ������� ����������: \n";
			cin>>a;			
		}

		cout<<"\n��������� �����: "<<randXor(a);
		a=0;

		cout<<"\n��� ������ ������� q - ����� ������ ������, ����� ����������: ";
		cin>>q;
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");

	randDialog();
	//tabulating();
	funcFibonacciInputOutput();
	//gcDivisorDialog();
	factorizationDialog();


	for(int i=3; i<40; i++)
		cout<<'\n'<<funcFibonacci(i+1)/(float)funcFibonacci(i);// ��������� � 1,61803


	int v=0;
	cin>>v;

	return 0;
}

/**********
##��9 �� 3/11##
1)�������� ������� ���������� �� ������� ��������� 
�������� ������� ���(a,b)

2) �������� ������������ ��������� ��������������� �����  (habrahabr.ru/company/infopulse/blog/329778/)
��� ����������� �������� ������������ ����������� ���������� �� ��������� ��������� �����, � ���� �����, ������� ����� ���� ������� �������.
������� �� �������� ������� ����� ������� ���������� ��������� ��������� ��������������� �����. ���������� � ������ ����� ������� �� ��� ��������
*�������� ������������ �����*.  
���� ������ ���������� � ���������� ���������� ���������������� ����� �� ����������� �� �������������� �������:  

x(n+1) = (a*x(n) + c) mod m;

��� x(n+1) ����� ��������������� �����, x(n) � ������, mod ��� ����������� �� ������, ��� ����������� ��������� ������������� ���������� �������
��� ������� �� m,  
1 <= a < m, 0 < c < m 
� m ��������� ������������, ������� � ���������� ������������������ ��������������� �����.  
�� ������ ����� ������������� ���������� ������������������ ������� �� ��������� �����, ��� �������� a = 7 c = 8 m = 16, ��������� ������������������
������������ 0 � 8.  
��� ������� ��������� ������ ���� ��������� ��������� �������:  
1. ����� c � m ������� �������;  
2. a - 1 ������ p ��� ������� �������� p, ����������� ��������� m;  
3. a - 1 ������ 4, ���� m ������ 4.  
����������� �������� ������������ ��������� ��������������� �����.  
(a) ��������� ������������ �� ���������, �������� a=4096, c=150889, m=714025.  
(b) �������� ����������� ������������ �� ��������, �� ��������� ������� ������������ �� ���������.  


3) � 2003 ���� ������ ��������� ��������� ������� �������� XORShift ��������� ���������������  ����� � �������������� XOR (� �++ ��� ��������
������������ ����� ���� ^ ) � �������� ��������. �������� ������� �� 3 ��������:

tmp = XOR(x(n),x(n)<<a) ;

tmp = XOR(tmp,tmp>>b) ;

x(n+1) = XOR(tmp,tmp<<c) ;

��������� �������� x(0) ����� �������� �����. ������� � ���� � �������� ��������� ����� (���������� srand(____) ��� ������ ������ � rand()).
����������� ����� �,b � � ����������� ��������������. 
� ���������, ��� 21, 35 � 4 ���������� ������������������ � ������ �������� ������ 2^64-1.

����� ������������ ����� 13,15,5.

���������� ���� �������� � �������� ��������� �������, ����� ����� ��������� ������� �� ������� (��� ��� ���� ���������� ������� ��������� ������)!
**********/
//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <ctime>

typedef int TYPE;

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

bool isSquare(int a)
{
	double root=sqrt(a);
	return (root-(int)root)==0;
}

void isSquareDialog()
{
	int a=0;

	char q=0;
	while(q!='q')
	{
		while(a<=0)
		{
			cout<<"\n������� ������������� ����� ������� 0: \n";
			cin>>a;			
		}

		cout<<"\n����� "<<a; isSquare(a)?cout<<" �������� ������ ��������� ":cout<<" �� �������� ������ ��������� ";
		a=0;

		cout<<"\n��� ������ ������� q - ����� ������ ������, ����� ����������: ";
		cin>>q;
	}
}
/*
void toBin(int a)
{
	int rez=1;
	int size=sizeof(a)*8;
	int mask=1;
		
	for (int i=size;i>=1;i--) //����� �������� �������� ����� ����� ������� (����� ���� 100000, ����� 010000 � �.�.)
	{            mask=(1<<(i-1));
	rez=(a&mask)>>(i-1);// ����������� �����, ���������� ��� ������� ����� �������, ����� ����� ���������� ������ �� ������ ������� �������
	//			 (���� ��������, 00100 - ����� 00001 - ����� ����� �������� �� 8, � 1 (��� �������� �������))

	cout<<setw(2)<<i<<"-�� ��� ����� "<<a<<" ����� "<<rez<<endl;
	}
}*/

void toBin(int a)
{
	int rez=1;
	int size=sizeof(a)*8;
	int mask=1;
		
	for (int i=size;i>=1;i--)
	{
		mask=(1<<(i-1));
		rez=a&mask;
		cout<<(rez!=0);
	}
}

void toBinDialog()
{
	int a=-1;

	char q=-1;
	while(q!='q')
	{
		a=-1;
		while(a<0)
		{
			cout<<"\n������� ����� ������������� �����: \n";
			cin>>a;			
		}

		toBin(a);

		cout<<"\n��� ������ ������� q - ����� ������ ������, ����� ����������: ";
		cin>>q;
	}
}

void toHex(int a)
{
	int rez=1;
	int size=sizeof(a)*8;
	int mask=1;
		
	for (int i=size/4;i>=1;i--)
	{
		mask=(15<<(i-1)*4);
		rez=(a&mask)>>(i-1)*4;
		if(rez<10)
		{
			cout<<rez;
			continue;
		}
		switch(rez)
		{
		case 10: cout<<'A';
			break;
		case 11: cout<<'B';
			break;
		case 12: cout<<'C';
			break;
		case 13: cout<<'D';
			break;
		case 14: cout<<'E';
			break;
		case 15: cout<<'F';
			break;
		}
	}
}

void toHexDialog()
{
	int a=-1;

	char q=-1;
	while(q!='q')
	{
		a=-1;
		while(a<0)
		{
			cout<<"\n������� ����� ������������� �����: \n";
			cin>>a;			
		}

		toHex(a);

		cout<<"\n��� ������ ������� q - ����� ������ ������, ����� ����������: ";
		cin>>q;
	}
}

void swap(int a, int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	char a='l', b='k';
	swap(a,b);
	cout<<a<<b;

	toBinDialog();
	toHexDialog();
	isSquareDialog();
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
##��9 �� 27/10##
(�������)
1) �� ���� ���������� ����������� �������� ������� ���, ����� main() �������� ��� ���������������� ����� ���������� �������. ��������,
void main(){
    int a,b,c;
    printCondition();/������� �������� ������� ������ � ������ ������ ��� ����� 
    cin>>a>>b>>c;
    if (checkSide(a,b,c)) return; /������� ��������� ������������� ������������
    calcArea(a,b,c); ������� ���������� ������� ������������ �� ������� ������ 
// ��� ��������� ������    
    sort3num(a,b,c); /������� "���������" ��� �����
    solveSquareEq(a,b,c);
    solveLinearEq(a,b,c);


2) ������� ������� 
isPrime(a); isSquare(a); *****
sumOfDgit(a); maxDigit(a); minDigit(a); reverse(); isPolindrom(a); 
toBin(a) �������� �������� ������������� �����, toHex(a);****
swap(a,b) ��� ���� ����� ������

printTriangle(n);/��������� ����������� ��������� ������� 
printTriangle(n,symb); ��������� symb ����������� ��������� ������� 
printRectangle(n,m,symb); ��������� symb ������������� ��������� ������� 



##�� �� 7/11##
1) �������� � ���� ��������� ��������� �������� ����� ���������. ��� ����� �������� � ������� ��������� ������������ � ����������� � ����������� � ������������ ��� ������ 40 ����� ��������� (long long int ������ ������� ��� ��������).  
2) �������� ���� � ����� ����� ��������� � �����������. ��� �� ������� ������ �� ��� ������. ��������� ��� � ���� ����� ������. ������ ������� ��������������. ���������� ����������� ���� �����-�� ��������� �������������� � �������������.    
3�) ������ "�������" ������� �� ���������� [a,b] � ����� h ���� ������� �������� min(y) � max(y) (��������, sin(2x)).
3�) ������ "�������" ������� �� ���������� [a,b] � ����� h ���� ���������� min(y) � max(y) (��������, x*sin(2x)). ������� ���������� ������� ����� ����� min(y) � max(y). ����� ��� ��� (��� � ���������� ������) ���������� ������� ����� ������� ������. 
4)*************** �� ������ �������� ����, �������� ���������� � �� ������� ������������� ���� � �������� �����. �������� ��������� ��������, ������� �� ��������� ����� ����������� ��� ������������ ���� � �����1.
(��� ����� ����� ������������ �������� � delLastDigit(a),delFirstDigit(a), reverse(a) � �.�.)
5) ��� "�����������" � ������ ���� � ���������� ���� � �������� � ������� �� ��������.
**********/
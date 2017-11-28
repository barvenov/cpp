//program by Piskunov Yury MMF IT 19 19102017

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

#pragma region Prime
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

void dialogPrimeOrNot()
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
}
#pragma endregion

const int SIZE_ARRAY=12;
int a[SIZE_ARRAY];

void inputArrayN(int a[], int n, char delim='\n')
{
	for(int i=0; i<n; i++)
	{
		cout<<delim<<" ������� ������� �: a["<<i<<"]= ";
		cin>>a[i];
	}	
}

const int MIN_RAND=0;
const int MAX_RAND=25;
int randX=1;

int randXor(int max=INT_MAX)
{
	int a=21, b=35, c=4;
	randX^=randX<<a;
	randX^=randX>>b;
	randX^=randX<<c;
	randX%=max;
	return randX>0?randX:-randX;
}

int randRange(int min=MIN_RAND, int max=MAX_RAND)
{	
	return (randXor()%(max-min+1))+min; //+1 for including MAX_RAND, range is the whole range i.g. -20, 50 --> 70 +bottom border
}

template <typename T>
void initArray(T a[], int n)
{
	for(int i=0; i<n; i++)
	{
		a[i]=randRange(-100);
	}
}

template <typename T>
void printArray(T a[], int n, char delim='\n')
{
	for(int i=0; i<n; i++)
	{
		cout<<delim<<" ������� ������� �: a["<<i<<"]= "<<a[i];
	}
}

template <typename T>//not working
void findMinMax(T a[], int n, T &min, T &max)
{
	T min=a[0], max=a[0];
	for(int i=1; i<n; i++)
	{
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
	}
}

template <typename T>
T findMin(T a[], int n)
{
	T min=a[0];
	for(int i=1; i<n; i++)
		if(a[i]<min) min=a[i];

	return min;
}

template <typename T>
T findMax(T a[], int n)
{
	T max=a[0];
	for(int i=1; i<n; i++)
		if(a[i]>max) max=a[i];

	return max;
}

int reversedArray[SIZE_ARRAY];

//template <typename T>
void reverseArray(int a[], int n)
{	
	for(int i=0; i<n; i++)
		reversedArray[i]=a[n-i-1];
}


int main()
{
	setlocale(LC_ALL, "Ru");

	
	while(1)
	{
		
		reverseArray(a, SIZE_ARRAY);
		initArray(a, SIZE_ARRAY);
		printArray(a, SIZE_ARRAY);
		cout<<"\nMin= "<<findMin(a, SIZE_ARRAY);
		cout<<"\nMax= "<<findMax(a, SIZE_ARRAY);

		printArray(reversedArray, SIZE_ARRAY);

		/*
		int min=0;
		int max=0;
		findMinMax(a, SIZE_ARRAY, min, max);*/

		char q=0;
		cout<<"\nEnter q - to quit: ";
		cin>>q;
		if(q=='q') break;
	}


	return 0;
}

/**********
printArray - ������� �������� ��������� ������� ������� N �� �����. 
inputArray - ������ �������� ��������� ������� ������� N � ����������. 
initArray - ������������������� �������� ��������� ������� ���������� �������. ������� rand() �� stdlib
���������� ����� ��������������� ����� � ��������� �� 0 �� RAND_MAX. ��� ��������� ����� ���������� � �����������
�� ����������� ��� ����������� ����������, � ��������, ��� ������������ �������� ���� ������ unsigned int. 
���������� �� ��������� � ������� �� ���������. �������, ��� � � ������� ��� ������ �������, ���� �������������� �������������
��� ��������, �������� � ���������� �� -10 �� 20.
findMin, findMax - ���������� �������� � ������� � ������� �.
**********/

/*****************

������ main ��������� ������ ���������� ����������. ������������� ������� - ��������� �������, ����� ������� - ��������� �������, 
����� ���������,�������� � �.�. - ��������� �������. 
����� ���� ������� - ������ main.
1) �������� ���� � ����-������ ����� ��������� � �����������. ������� ������ �����, ��������� ������ ��������� �� ��� ���, 
���� �� ������� ���������� �����.
2) �������� � ��������� ��� ��� ��������� � 
printArray,inputArray,initArray,findMin, findMax
reverse (� ����� ������ ���������� �������� � "�������� �������" (������� �� ���������� �������� �
���������� ������)
3) �������� ������� 
sumArray - ����� ���� ��������� � ������� �.
positiveNegativeArray - ������� ���-�� ������������� � ���������� ������������� ��������� � ������� �.(��������������, ��� ��������� �������� ����� ��� �������� ������ �����!)
howMuch - ������� ���-�� ��������� � ������� �, ������� ��������� � ��������� ������ number.

halfArray - "���������" ������ � �� ��� �������: ������ �������� - � ������ �, ��������� - �
�. (����������� ����������� ������ ����� N ��������!)
divArray - "���������" ������ � �� ��� �������: ������������� �������� � ������ �, ������������� -
� �.

changeArray ����� ������� �������� �������� � ������� (����� ������������ ��������, �����
������������ ���������) �������� �������� �� ����� 999. ��� ������ � ������, ����� �� ������� �� ������� ������� ������ ����������� (�.�. ��).

howManyMaxMin ������� ���-�� ������������ � ���������� ����������� ��������� � ������� �.
���� ����� ������ ����������� �� ���� ������ �� �������! (���������, ��� ��������� �������� �� ������� {2,3,4,4,4,5,5,2,5}. � ���� ������� �������� ����������� 3 ���� � ������� 2 ����!)

4) �������� ������ � ������������ ����� ������� N (����� N �������� ��� ���������).
������������������� �������� ��������� ������� ���������� ������� �� ����������
�� -50 �� 50. "�������������������" ������ � (�.�. ��������� ��������������� ������ �).
������������� �������� ������� � ����������� � ������ �, �������������
����������� � ����� ������� �.
(��������� �����, ��� ��������� �������� ����� ��� �������� ������ �����!)

5) ***. �������� ��������� "����������� ������������ ��������� ������� �" �� 1
������� ����� (����� �� 1 ��������� ������). 
�.�. 1-� ������� � ���������� 2-�� � ����� ������� �, 2-� ���������� 3-� �
��� �����. ���� ��������� ����� ������� �, �� ��������� ������� � ������ 1!
������ �� ��� ��������� ����� ������� ��������� ��������, ����� �������� ����� ������ ��
������� �. ������� ��� �������� mod � ������� ;-)

*****************/
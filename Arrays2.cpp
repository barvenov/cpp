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
void initArray(T a[], int n, int min=-100, int max=100, int divisor=1)
{
	for(int i=0; i<n; i++)
	{
		a[i]=randRange(min, max)/(T)divisor;
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

int reversedArray[SIZE_ARRAY]={};

template <typename T>
void reverseArray(T a[], int n)
{	
	for(int i=0; i<n; i++)
		reversedArray[i]=a[n-i-1];	
}

template <typename T>
T sumArray(T a[], int n)
{
	T sum=0;
	for(int i=0; i<n; i++)
		sum+=a[i];
	return sum;
}

template <typename T>
T howMuchEquals(T a[], int n, T number)
{
	int total=0;
	for(int i=0; i<n; i++)
		if(a[i]==number) total++;
	return total;
}

template <typename T>
void positiveNegativeArray(T a[], int n, int &negatives, int &positives)
{
	positives=negatives=0;	
	for(int i=0; i<n; i++)
		if(a[i]>=0) positives++;
		else negatives++;
}

/*
bool ifOddFirstMore=false;

int b[];
int c[];

template <typename T>//in proccess!!!   !!!!    !!  how to do a definite size
void divArray(T a[], T n, bool ifOdd_FirstMore=false)
{	
	for(int i=0; i<n; i++)
		if(i<(n/2+(int)ifOdd_FirstMore)) {b[]=b[n/2+(int)ifOdd_FirstMore)]; b[i]=a[i];}
		else {c[]=c[n/2+(int)!ifOdd_FirstMore)]; c[i-n/2]=a[i];}
}*/

enum changeOption
{
	afterZero, afterMin, beforeMax
};

template <typename T>
void changeArray(T a[], int n, changeOption changeOption)	
{
	bool wasntEarlier=true;
	for(int i=0; i<n; i++)
		switch(changeOption)
	{
		case afterZero: if(i<n-1&&a[i]==0&&wasntEarlier) {a[i+1]=999; wasntEarlier=false;}
			break;
		case afterMin: if(i<n-1&&a[i]==findMin(a, n)&&wasntEarlier) {a[i+1]=999; wasntEarlier=false;}
			break;
		case beforeMax: if(i&&a[i]==findMax(a, n)&&wasntEarlier) {a[i-1]=999; wasntEarlier=false;}
			break;
	}		
}

template <typename T>
void howManyMaxMin(T a[], int n, int &minQuantity, int &maxQuantity)
{
	minQuantity=maxQuantity=0;	
	for(int i=0; i<n; i++)
		if(a[i]==findMin(a, n)) minQuantity++;
		else if(a[i]==findMax(a,n)) maxQuantity++;
}

template <typename T>
void copyArrayA(T a[], T b[], int n)
{
	for(int i=0;i<n;i++)
		b[i]=a[i];
}

template <typename T>
void pseudoSort(T a[], T b[], T c[], int n)
{
	T temp=0;
	int positives=0;
	copyArrayA(a, b, n);
	for(int i=0; i<n; i++)
	{
		for(int j=0;j<n-i-1;j++)
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
			if(b[n-i-1]>=0) positives++;
	}

	for(int i=0; i<n; i++)
		if(i<positives) c[i]=b[n-positives+i];
		else c[i]=b[i-positives];
		copyArrayA(c,b,n);
}


void reverseArraytt(int a[], int tt[], int n)
{	
	for(int i=0; i<n; i++)
		reversedArray[i]=a[n-i-1];
	//printArray(reversedArray, n);
}




const int Nloop=8;
int aLoop[Nloop];

void loopShiftLeft(int a[], int n) //naive way
{
	int temp=0;
	int begin=a[0];
	for(int i=1;i<n-1;i++)
	{
		temp= a[i];
		a[i]=a[i+1];
		a[i-1]=temp;
	}
	a[n-1]=begin;
}

void loopShiftLeft2(int* a, int n)
{
	int begin=a[0];
	a+=sizeof(int)*8;
	a[n-1]=begin;
}

int main()
{
	setlocale(LC_ALL, "Ru");

	
	while(1)
	{
		cout<<sizeof(int)*8;
		initArray(aLoop, Nloop);
		printArray(aLoop, Nloop);

		loopShiftLeft2(aLoop, Nloop);
		printArray(aLoop, Nloop);
		/*int tt[SIZE_ARRAY];
		reverseArraytt(a, tt, SIZE_ARRAY);*/
		/*//main
		int negatives=0, positives=0;
		int minQuantity=0, maxQuantity=0;

		initArray(a, SIZE_ARRAY);
		printArray(a, SIZE_ARRAY);
		
		positiveNegativeArray(a, SIZE_ARRAY, negatives, positives);

		cout<<"\nMin= "<<findMin(a, SIZE_ARRAY);
		cout<<"\nMax= "<<findMax(a, SIZE_ARRAY);
		cout<<"\nNegatives= "<<negatives;
		cout<<"\nPositives= "<<positives;
		cout<<"\nSum= "<<sumArray(a, SIZE_ARRAY);
		cout<<"\nTotal number of equal to 8 in array= "<<howMuchEquals(a, SIZE_ARRAY, 8);
		
		reverseArray(a, SIZE_ARRAY);
		printArray(reversedArray, SIZE_ARRAY);

		changeArray(a, SIZE_ARRAY, afterMin);
		printArray(a, SIZE_ARRAY);


		int b[]={2,3,4,4,4,5,5,2,5};
		cout<<(int)sizeof(b)/(int)sizeof(int);
		howManyMaxMin(b, (int)sizeof(b)/(int)sizeof(int), minQuantity, maxQuantity);
		cout<<"\nThe quantity of minimal elements= "<<minQuantity;
		cout<<"\nThe quantity of mmaximal elements= "<<maxQuantity;

		const int N=20;
		float A[N]={}, B[N]={}, C[N]={};
		initArray(A, N, -5000, 5000, 100.0);
		pseudoSort(A,B,C,N);
		printArray(B,N);*/


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
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
		cout<<delim<<" Элемент массива а: a["<<i<<"]= ";
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
		cout<<delim<<" Элемент массива а: a["<<i<<"]= "<<a[i];
	}
}

template <typename T>//not working потому, что в сроке 94 вы еще раз объявляете переменные max и min, которые передали как параметры
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
printArray - Вывести значения элементов массива размера N на экран. 
inputArray - Ввести значения элементов массива размера N с клавиатуры. 
initArray - Проинициализировать значения элементов массива случайными числами. Функция rand() из stdlib
возвращает целое псевдослучайное число в промежуке от 0 до RAND_MAX. Эта константа может отличаться в зависимости
от компилятора или архитектуры процессора, в основном, это максимальное значение типа данных unsigned int. 
Параметров не принимает и никогда не принимала. Поэтому, как и в задании про график функции, надо самостоятельно преобразовать
эти значения, например в промежуток от -10 до 20.
findMin, findMax - возвращает максимум и минимум в массиве А.
**********/

/*****************

Внутри main находится только объявление переменных. Инициализация массива - отдельная функция, вывод массива - отдельная функция, 
поиск максимума,минимума и т.п. - отдельная функция. 
Вызов этих функций - внутри main.
1) Напишите игру в быки-коровы между человеком и компьютером. Человек вводит числа, компьютер выдает подсказки до тех пор, 
пока не угадано загаданное число.
2) отладить и проверить что все нормально в 
printArray,inputArray,initArray,findMin, findMax
reverse (в новый массив записываем значения в "обратном порядке" (начиная от последнего элемента и
заканчивая первым)
3) написать функции 
sumArray - сумма всех элементов в массиве А.
positiveNegativeArray - Вывести кол-во положительных и количество отрицательных элементов в массиве А.(Протестировать, что программа работает когда все элементы одного знака!)
howMuch - Вывести кол-во элементов в массиве А, которые совпадают с некоторым числом number.

halfArray - "Разделить" массив А на два массива: первую половину - в массив В, остальные - в
С. (Внимательно рассмотреть случай когда N нечетное!)
divArray - "Разделить" массив А на два массива: положительные записать в массив В, отрицательные -
в С.

changeArray После первого нулевого элемента в массиве (после минимального элемента, перед
максимальным элементом) заменить значение на число 999. Что делать в случае, когда мы выходим за границы массива решает программист (т.е. Вы).

howManyMaxMin Вывести кол-во максимальных и количество минимальных элементов в массиве А.
Этот поиск должен выполняться за один проход по массиву! (Проверить, что программа работает на массиве {2,3,4,4,4,5,5,2,5}. В этом массиве максимум встречается 3 раза и минимум 2 раза!)

4) Объявить массив А вещественных чисел размера N (число N объявить как константу).
Проинициализировать значения элементов массива случайными числами из промежутка
от -50 до 50. "ПсевдоОтсортировать" массив А (т.е. заполнить вспомогательный массив В).
Положительные значения массива А переместить в начало В, отрицательные
переместить в конец массива В.
(Проверить потом, что программа работает когда все элементы одного знака!)

5) ***. Написать программу "циклической перестановки элементов массива А" на 1
элемент влево (потом на 1 элементов вправо). 
Т.е. 1-й элемент А становится 2-ым в новом массиве В, 2-й становится 3-м и
так далее. Если достигаем конца массива В, то заполняем начиная с номера 1!
Требую от вас придумать некую формулу изменения индексов, чтобы обойтись одним циклом по
массиву А. Думайте про операцию mod в алгебре ;-)

*****************/

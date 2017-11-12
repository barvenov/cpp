//program by Piskunov Yury MMF IT 19 10102017

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

void stateMessage(int store)
{
	cout<<"\nThe lift is at the "<<store<<" store.\n";
}

void up()
{
	cout<<"\n��� �����...";
}
void down()
{
	cout<<"\n��� ����...";
}

void liftAtTheSameStore(bool upMoving)
{
	cout<<"\n������ ����������... ����� ��'��� �� ��������i ������� ������ ����������.\nMind your head.";
	if(upMoving) up();
	else down();
	cout<<"\n������ ����������... See you soon sir\n\n";	
}

void initLiftAtAnotherStore(bool initUpMoving)
{
	cout<<"\n������ ����������... ����� ��'��� �� ��������i ������� ������ ����������.\n(�� ������ ������ - ����� ��� ����)";
	if(initUpMoving) up();
	else down();
	cout<<"\n������ ����������... Welcome on board sir";
	liftAtTheSameStore(!initUpMoving);//�.�. ���� ��� ������������� �� ��������� ����� ������� � �������������� ������ �����������
}


int main()
{
	setlocale(LC_ALL, "Ru");

	int storeDestination=0;
	int storeInitial=1;
	int myPosition=0;

	bool noSense=true;
	bool itWasThere=false;
	bool initUpMoving=false;
	bool upMoving=true;

	/*******
	�������� ������� �� ���� ���������� - ��������� �����, ��������� ��������, ������� ������.
	�� ��������� ���� ������� - �������� �� �������� �����������.�� ��� ���.
	������������, ����
	1) ������� �� ������ � ���� �����;
	2) ������� �� ������� � ���� ����.
	����� �������� �� �����/����������� �������� ���������� �������� ������� �� ���� - ��� ��������� ����:
	1) �� ��� �� �����, �����: ����� ������ ����������� � ���� ���� ���� ����� - ����� �����������, ������� �������
	2) �� ������ ����� - ����� �����������, ���� ���� � ��������, ����� ����������� - ���������� ������ ���� (���� �� ��� �� �����)
	*******/
	while(true)
	{
		noSense=true;	
		stateMessage(storeInitial);
		cout<<"\nEnter a store where you are\n";
		cin>>myPosition;

		//�������� �� ����������
		while(noSense)
		{
			cout<<"\nPress button: 1 - to move up, 0 - to move down\n";		
			cin>>storeDestination;
			if(!(storeDestination-myPosition))
			{
				cout<<"Action doesn't have sense because you are at the destination store";
				continue;
			}
			else if(storeDestination<0||storeDestination>1) cout<<"Wrong command";
			else noSense=false;
		}

		//�������� ����� ��������� ����� ����� ������ � �� �������� �� ����������

		//������ ���������� ���� �� ����� �����: ����� ��� ����
		if(storeDestination-myPosition>0) upMoving=true;
		else upMoving=false;

		//� ����������� �� ����, ��������� �� ���� �� ��� �� ����� ��� � ������� - ��� ���, ���������� ���� �� �������
		if(myPosition-storeInitial==0)
		{
			liftAtTheSameStore(upMoving);
			
		}
		else
		{
			if(myPosition-storeInitial>0) initUpMoving=true;
			else if(myPosition-storeInitial<0) initUpMoving=false;
			initLiftAtAnotherStore(initUpMoving);
		}

		storeInitial=storeDestination;//������ ��������� ����� �� ��� �������� �� ��������� ����
		

		//storeInitial=rand()%2;	������ rand ��� ����� �������� - ������ ���� � �� �� �������� 41 � ������ � ����� ��������	
	}


	int v=1;
	cin>>v;
	return 0;
}



/*

� ����� ������ � �������� ������ �������� ����� ������� ��������. ��� ������� �� ������ ������ ���� ����������� �� ���� ���� �����,
� ��� ������� �� ������ � ���������� �� ���� ���� ����. ���� ������������� ��������� �� ������������ ����� � ��������� �������. 
�� ����� ��������� 4 ��������: �������/������� �����, ���������/����������. ����������������� ���������� ���� ������:
������������ �������� ��� ������ ����. �� "��������" �� ������ � �����. 
���� �������� "����������" (��������, �� �� 1� ����� � ����� ����� �����) 
�� ������ ������������ �������. ���� �������� ���������, �� ���� ��������� ����� �������� (������-������-������),
�������� �� � ����� ���� ����� �� ������������.
P.S. ����������� ���� ��������� �������� ������������ ������������ ���:
while(1) {
cout<<"���� ����? 1-�����, 2 - ����";
cin>>doing;

// ��� ��� ���

}

*/
#include <iostream>

//�ʼ� ��� ���̵�
using namespace std;

void avrg(int arr[])
{
	int avr = 0;
	for (int i = 0; i < 5; i++)
	{
		avr += arr[i];
	}
	cout << avr / 5 <<endl;
}

void plu(int arr[])
{
	int avr = 0;
	for (int i = 0; i < 5; i++)
	{
		avr += arr[i];
	}
	cout << avr << endl;
}

void sortup(int arr[])
{
	int stack = 0;
	int Max = 5;
	for (size_t j = 0; j < 4; j++)
	{
		for (int i = 1; i < Max; i++)
		{
			if (arr[stack] > arr[i])
			{
				int temp = 0;
				temp = arr[i];
				arr[i] = arr[stack];
				arr[stack] = temp;
			}
			stack++;
		}
		stack = 0;
		Max--;
	}
	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
}

void sortdown(int arr[])
{
	int stack = 0;
	int Max = 5;
	for (size_t j = 0; j < 4; j++)
	{
		for (int i = 1; i < Max; i++)
		{
			if (arr[stack] < arr[i])
			{
				int temp = 0;
				temp = arr[i];
				arr[i] = arr[stack];
				arr[stack] = temp;
			}
			stack++;
		}
		stack = 0;
		Max--;
	}
	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
}

void main()
{
	int a = 0;
	int arr[5];
	cout << "�ʼ�:1 ����:2 �Է��Ͻÿ�" << endl;
	cin >> a;
	cout << "���ڸ� �� 5�� �Է��Ͻÿ�";
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	switch (a)
	{
	case 1:
		avrg(arr);
		plu(arr);
		break;
	case 2:
		sortup(arr);
		cout << endl;
		sortdown(arr);
	default:
		
		break;
	}
}
/*) ��� ������������� ������ �� N ���������. �������� ���������, �����������
����� � ������� ������������ ��������� �������, ������� ����� ��������
�������� � ������� �� 3. �������������, ��� � �������� ������� ���� ���� ��
���� �������, �������� �������� ������� � ������ 3. ��������� ������ ����
���������� �� ������� � ������*/



#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int i, comp = 1, n;
	cin >> n;
	int *s =  new int[n];
	for(i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for(i = 1; i < n; i++)
	{
		if(s[i] % 2 != 0 && s[i] % 3 == 0)
       comp = comp * s[i];
	}
	delete []s;
	cout << comp;
	return 0;
}
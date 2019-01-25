/*Напишите программу, находящую для заданной последовательности длины N
целых чисел необходимо: минимальное произведение двух её элементов, номера
которых различаются не менее чем на 5. Программа должна быть эффективной по
времени и памяти.*/



#include <iostream>
using namespace std;
int main() {
	int m = 2147483647;
	int mx = 2147483647;
	int x;
	int d = 5;
	int N;
	cin >> N;
	int *array = new int[d - 1];
	for (int i = 0; i < d; i++)
	{
		cin >> x;
		array[i % d] = x;
	}
	for (int i = d; i < N; i++)
	{
		cin >> x;
		if (array[i % d] < mx)
			mx = array[i % d];
		if (x * mx < m)
		{
			m = x * mx;
			array[i % d] = x;
		}
	}
	cout << m;
	return 0;
}

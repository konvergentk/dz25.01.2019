/*) Напишите программу, находящую для заданной последовательности длины N
неотрицательных целых чисел необходимо: максимальную сумму двух её
элементов, номера которых различаются не менее чем на 5. Программа должна
быть эффективной по времени и памяти*/



#include <iostream>
using namespace std;
int main() {
	int m = 0;
	int z = 0;
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
		if (array[i % d] > z) {
			z = array[i % d];
		}
		if (x + z > m) {
			m = x + z;
			array[i % d] = x;
		}
	}
	cout << m;
	return 0;
}

/*Дан набор из N целых положительных чисел. Необходимо определить, какая
цифра чаще всего встречается в десятичной записи чисел этого набора. Если
таких цифр несколько, необходимо вывести их все в порядке убывания — от
большей к меньшей. Напишите эффективную по времени и по памяти программу
для решения этой задачи.*/



#include <iostream>
using namespace std;
int main() {
	int N, X, number, MAX;
	int *array = new int[9];
	for (int i = 0; i < 9; i++) {
		array[i] = 0;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X;
		while (X > 0)	{
			number = X % 10;
			array[number]++;
			X = X / 10;
		}
	}
	MAX = 0;
	for (int i = 0; i < 9; i++) {
		if (array[i] > MAX) {
			MAX = array[i];
		}
	}
	for (int i = 9; i > 0; i--) {
		if (array[i] == MAX) {
			cout << i << " ";
		}
	}
	return 0;
}

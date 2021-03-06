/*На пустой шахматной доске NxN в одной из клеток стоит шахматный конь.
Напишите программу, получающую список клеток, которые конь может достичь не
более чем 3 хода из данной клетки. На вход программы поступают два целых
числа: х, у (1 ≤ х,у ≤ N) — координаты клетки, в которой стоит конь. На выходе
программы должен быть выведен список пар целых чисел — координаты клеток,
достижимых конём из исходной клетки за один ход*/



#include "pch.h"

#include <iostream>

using namespace std;

void R(int x, int y, int n, int N)
{
	if ((x >= 0) && (y >= 0))
	{
		if(n == 3)
			cout << x << " " << y << endl;
		else
		{
		    R(x + 2, y + 1, n + 1, N);

        R(x + 2, y - 1, n + 1, N);

        R(x - 2, y + 1, n + 1, N);

        R(x - 2, y - 1, n + 1, N);

        R(x + 1, y + 2, n + 1, N);

        R(x + 1, y - 2, n + 1, N);

        R(x - 1, y - 2, n + 1, N);

        R(x - 1, y + 2, n + 1, N);
		}
}
}
int main()
{
	int x, y, n = 0, N;
	cin >> x >> y >> N;
	R(x, y, n, N);
	return 0;
}

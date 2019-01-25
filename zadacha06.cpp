/*У исполнителя четыре команды, которым присвоены номера:
1. Прибавить 2
2. Прибавить 4
3. Прибавить 5
4. Умножить на 3
Напишите программу, находящую самую короткую программу, получающую из
числа X число Y, такую, что в промежуточных действиях обязательно появляется
число Z. Программа должна выписать программу, как последовательность команд.
Если такой программы нет – выписать NO. Если коротких программ несколько –
выписать любую из них.
*/



#include <iostream>
#include <math.h>
using namespace std;
int H;
int *a;
int *b;
int R( int x, int y, int z, int N)
{
    int n = 0;
    if ( x < y && y != z)
    {
            if ( y - 2 >= x)
            {
                b[ N ] = 1;
                n = R( x, y - 2, z, (N + 1));
            }
            if ( y - 4 >= x)
            {
                b[N] = 2;
                n = R( x, y - 4, z, (N + 1));
            }
            if ( y - 5 >= x)
            {
                b[N] = 3;
                n = R( x, y - 5, z, (N + 1));
            }
            if ( y % 3 == 0 )
            {
                b[N] = 4;
                n = n + R( x, y/3, z, N + 1);
            }
    }
    else if ( x == y)
    {
        n = 1;
        if ( N <  H )
        {
            H = N;
            memcpy( a, b, N * sizeof(int));
        }
    }
    return n;
}
int main()
{
    int x, y, n, z;
    cin >> x >> y >> z;
    H = y - x;
    a = new int [H];
    for (int i = 0; i <  H; i++ )
    {
        a[i] = 1;
    }
    b = new int [H];
    n = R( x, y, z, 0);
    cout << H << endl;
    if ( n == 0)
        cout << "NO";
    if ( n != 0)
    {
    for ( int i = 0; i < H; i++ )
        cout << a[i] << " ";
    }
    delete []a;
    delete []b;
    return 0;
}

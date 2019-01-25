/*Ó èñïîëíèòåëÿ ÷åòûðå êîìàíäû, êîòîðûì ïðèñâîåíû íîìåðà:
1. ïðèáàâü 9
2. âîçâåäè â êâàäðàò
3. óìíîæü íà 7
4. ïðèïèøè 1 â êîíåö
Ïåðâàÿ èç íèõ óâåëè÷èâàåò íà 9 èñõîäíîå ÷èñëî x, òðåòüÿ óìíîæàåò ýòî ÷èñëî íà 7,
âòîðàÿ ïåðåâîäèò ÷èñëî x â ÷èñëî x*x, ÷åòâ¸ðòàÿ äîáàâëÿåò ê ÷èñëó åäèíèöó â
êîíåö (íàïðèìåð, èç ÷èñëà 30 ïîëó÷àåòñÿ ÷èñëî 301). Ïðîãðàììà äëÿ èñïîëíèòåëÿ
— ýòî ïîñëåäîâàòåëüíîñòü êîìàíä. Íàïèøèòå ïðîãðàììó, ïðîâåðÿþùóþ, ìîæíî ëè
ïîñëåäîâàòåëüíîñòüþ êîìàíä èñïîëíèòåëÿ ïîëó÷èòü èç ÷èñëà X ÷èñëî Y. Åñëè
ìîæíî, ïðîãðàììà äîëæíà âûïèñûâàòü YES, â ïðîòèâíîì ñëó÷àå – NO.*/



#include <iostream>
#include <cmath>
using namespace std;
bool sqr(long long n) {
	long long squareRootN = (long long)(sqrt((double)n) + 0.5);
	return squareRootN * squareRootN == n;
}
int main() {
	int X, Y;
	cin >> X >> Y;
	bool *d = new bool[Y + 1];
	for (long long i = 0; i <= Y; i++) {
		if (i == X) {
			d[i] = 1;
		}
		else if (i <= X) {
			d[i] = 0;
		}
		else if ((sqr(i) == true) && (i % 7 == 0) && (i % 10 == 1)) {
			d[i] = d[i - 9] || d[(int)sqrt(i)] || d[i / 7] || d[(i - 1) / 10];
		}
		else if ((sqr(i) == true) && (i % 7 == 0) && (i % 10 != 1)) {
			d[i] = d[i - 9] || d[(int)sqrt(i)] || d[i / 7];
		}
		else if ((sqr(i) == true) && (i % 7 != 0) && (i % 10 == 1)) {
			d[i] = d[i - 9] || d[(int)sqrt(i)] || d[(i - 1) / 10];
		}
		else if ((sqr(i) == true) && (i % 7 != 0) && (i % 10 != 1)) {
			d[i] = d[i - 9] || d[(int)sqrt(i)];
		}
		else if ((sqr(i) == false) && (i % 7 != 0) && (i % 10 != 1)) {
			d[i] = d[i - 9];
		}
		else if ((sqr(i) == false) && (i % 7 == 0) && (i % 10 == 1)) {
			d[i] = d[i - 9] || d[i / 7] || d[(i - 1) / 10];
		}
		else if ((sqr(i) == false) && (i % 7 == 0) && (i % 10 != 1)) {
			d[i] = d[i - 9] || d[i / 7];
		}
		else if ((sqr(i) == false) && (i % 7 != 0) && (i % 10 == 1)) {
			d[i] = d[i - 9] || d[(i - 1) / 10];
		}

	}
	if (d[Y] == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}

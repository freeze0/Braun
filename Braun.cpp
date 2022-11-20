#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

double f(double x, double y) {
	return sin(x * x) + y * y;

}

double g(double x, double y) {
	return exp(x) - y;

}

double dfx(double x, double y) {
	return 2 * x * cos(x * x);
}

double dfy(double x, double y) {
	return 2 * y;
}

double dgx(double x, double y) {
	return exp(x);
}

double dgy(double x, double y) {
	return -1;
}

int main()
{
	setlocale(LC_ALL, ".1251");

	double eps = 0.000001, x = 1, y = 1;
	
	double xNext = x, yNext = y, pNext = 3, qNext = 3, q, p;
	do {
		q = qNext;
		p = pNext;
		x = xNext;
		y = yNext;
		double xp = x - f(x, y) / dfx(x, y);
		qNext = (g(xp, y) * dfx(x, y)) / (dfx(x, y) * dgy(x, y) - dfy(x, y) * dgx(xp, y));
		pNext = (f(x, y) - qNext * dfy(x, y)) / dfx(x, y);

		xNext = x - pNext;
		yNext = y - qNext;


	} while (max(q, p) > eps);



	cout << "Решение системы:" << endl << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	return 0;
}
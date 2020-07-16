#include <bits/stdc++.h>
using namespace std;

int gcdex(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcdex(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}


//14x + 15y = 

int main() {
	
	int a, b, c;
	cin >> a >> b >> c;
		
	int x, y;
	int g = gcdex(a, b, x, y);
	if (c % g != 0) {
		cout << "no";
 	} else {
		int d = c / g;
		x *= d;
		y *= d;
		cout << a << '*' << x << '+' << b << '*' << y << '=' << c;
		assert(a * x + b * y == c);
	}
	
}

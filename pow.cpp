#include <iostream>

using namespace std;


double power(double x, int y)
{
	if (y == 0) {
		return 1;
	}
	else if (y < 0) {
		return (1 / power(x, -y));
	}
	else {
		return x * power(x, y - 1);
	}
}

int main()
{
	cout << "To calculate x^y ..." << endl;

	double x;
	int y;
	cout << "Please enter x: ";
	cin >> x;
	cout << "Please enter y: ";
	cin >> y;

	if (x == 0) {
		if (y > 0)
			cout << 0 << endl;
		else
			cout << "x^y is not defined" << endl;
	}
	else
		cout << power(x, y) << endl;

	return 0;
}


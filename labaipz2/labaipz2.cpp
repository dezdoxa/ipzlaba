#include <iostream>
#include <fstream>
using namespace std;

int main() {
	bool toSave;
	double a, b, h, n;
	cout << "enter a, b, h, n: ";
	cin >> a >> b >> h >> n;
	if (h <= 0) {
		cout << "error: invalid h." << endl;
		return 1;
	}
	if (n < 1) {
		cout << "error: invalid n." << endl;
		return 1;
	}
	for (double x = a; x <= b; x += h) {
		double y = 0;
		if (x >= 0) {
			for (int i = 0; i <= n; i++) {
				double t = 1;
				for (int j = 1; j <= n; j++) {
					t *= (x + i) / (i + j);
				}
				y += t;
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				y += (i + x) * (i + x);
			}
		}
		cout << "do you want to save data? (1/0)" << endl;
		cin >> toSave;
		ofstream fout("data.txt");
		for (x; x <= b; x += h) {
			if (toSave) {
				fout << "y = " << y << endl;
				fout << "x = " << x << endl;
			}
			else {
				cout << "y = " << y << endl;
				cout << "x = " << x << endl;
			}
		}
	}
	return 0;
}
# Build the Polynomial class.

```C++
// xay dung lop da thuc
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
using namespace std;

class Dathuc {
private:
	int level;
	double* arr;
public:
	Dathuc() {
		level = 0;
		arr = NULL;
	}

	Dathuc(int level, double* arr) {
		this->level = level;
		this->arr = arr;
	}

	void input() {
		cout << "\nNhap bac da thuc: ";
		cin >> this->level;
		cout << "\nNhap he so: ";
		this->arr = new double[this->level + 1];

		for (int i = 0; i <= this->level; i++) {
			cin >> arr[i];
		}
	}

	void display() {
		cout << "\nDa thuc: \n";
		int curr = this->level;
		for (int i = 0; i <= this->level; i++) {
			if (curr != 0)
				cout << this->arr[i] << ".x^" << curr << " + ";
			else
				cout << this->arr[i] << ".x" << endl;
			curr--;
		}
	}
	void PrintHS() {
		cout << "\nHe so cua da thuc: ";
		for (int i = 0; i <= this->level; i++) {
			cout << this->arr[i] << " ";
		}
	}

	friend double Calc(Dathuc A, double x) {
		double res = 0;
		int curr = A.level;
		for (int i = 0; i <= A.level; i++) {
			res += (A.arr[i] * pow(x, curr--));
		}
		return res;
	}

	friend istream& operator>>(istream& is, Dathuc& A) {
		cout << "\nNhap bac da thuc: ";
		is >> A.level;
		cout << "\nNhap he so: ";
		A.arr = new double[A.level + 1];

		for (int i = 0; i <= A.level; i++) {
			is >> A.arr[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Dathuc A) {
		os << "\nDa thuc: \n";
		int curr = A.level;
		for (int i = 0; i <= A.level; i++) {
			if (curr != 0)
				os << A.arr[i] << ".x^" << curr << " + ";
			else
				os << A.arr[i] << ".x" << endl;
			curr--;
		}
		return os;
	}
};

int main() {
	// Excercise 1:

	Dathuc P;
	cin >> P;
	cout << P;
	double d1, d2;
	cout << "\nNhap d1 = "; cin >> d1;
	cout << "Nhap d2 = "; cin >> d2;

	cout << "P(" << d1 << ") + P(" << d2 << ") = " << Calc(P, d1) << " + " << Calc(P,d2) << " = " << (Calc(P,d1) + Calc(P,d2)) << endl;

	return 0;
}
```
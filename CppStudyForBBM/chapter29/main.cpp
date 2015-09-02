#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void sort(vector<T>& v) {
	for (vector<T>::size_type i = 0; i < v.size(); i++) 	{
		for (vector<T>::size_type j = 0; j < v.size() - 1; j++) {
			T temp = 0;
			if (v[j] > v[j + 1]) {
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void print(vector<T>& v) {
	for (vector<T>::size_type i = 0; i < v.size(); i++) 	{
		cout << v[i] << endl;
	}
}

int main() {
	vector<int> a(10);
	vector<double> b(10);

	for (vector<int>::size_type i = 0; i < a.size(); i++) 	{
		a[i] = 10 - i;
	}
	for (vector<double>::size_type i = 0; i < b.size(); i++) 	{
		b[i] = (double)(10 - i);
	}

	sort(a);
	sort(b);

	print(a);
	cout << endl;
	print(b);
	return 0;
}
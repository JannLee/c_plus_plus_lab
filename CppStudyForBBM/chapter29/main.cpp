#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class vector {
public:
	vector();
	vector(int size);
	vector(const vector& other);
	T get(int index);
	int getSize();
	vector& set(int index, T value);
	vector& pushback(T value);
	vector& pushfront(T value);
	vector& operator= (const vector& other);
	~vector();
private:
	int size;
	T* values;
};
template <typename T> vector<T>::vector() {
	this->size = 32;
	this->values = new T[size];
	for (int i = 0; i < size; i++) {
		this->values[i] = 0;
	}
};
template <typename T> vector<T>::vector(int size) {
	if (size < 1) {
		size = 32;
	}
	this->size = size;
	this->values = new T[size];
	for (int i = 0; i < size; i++) {
		this->values[i] = 0;
	}
};
template <typename T> vector<T>::vector(const vector& other) {
	this->values = new T[other.size];
	this->size = other.size;
	for (int i = 0; i < other.size; i++) {
		this->values[i] = other.values[i];
	}
};
template <typename T> vector<T>::~vector() {
	delete this->values;
};
template <typename T> T vector<T>::get(int index) {
	if (index >= this->size) {
		return -1;
	}
	return this->values[index];
};
template <typename T> int vector<T>::getSize() {
	return this->size;
};
template <typename T> vector<T>& vector<T>::set(int index, T value){
	if (index >= this->size) {
		return *this;
	}
	this->values[index] = value;
	return *this;
};
template <typename T> vector<T>& vector<T>::pushback(T value){
	this->size = this->size + 1;
	T* temp = new T[size];
	for (int i = 0; i < this->size - 1; i++) {
		temp[i] = this->values[i];
	}
	temp[size - 1] = value;
	delete this->values;
	this->values = temp;
	return *this;
};
template <typename T> vector<T>& vector<T>::pushfront(T value){
	this->size = this->size + 1;
	T* temp = new T[size];
	for (int i = 1; i < this->size; i++) {
		temp[i] = this->values[i - 1];
	}
	temp[0] = value;
	delete this->values;
	this->values = temp;
	return *this;
};
template <typename T> vector<T>& vector<T>::operator= (const vector& other) {
	if (this == &other) {
		return *this;
	}

	delete values;
	this->values = NULL;

	this->values = new T[other.size];
	this->size = other.size;
	for (int i = 0; i < other.size; i++) {
		values[i] = other.values[i];
	}
};
template <typename T>
void print(vector<T>& v) {
	cout << "header : " << endl;
	for (int i = 0; i < v.getSize(); i++) {
		cout << i << "\t";
	}
	cout << endl;
	cout << "values : " << endl;
	for (int i = 0; i < v.getSize(); i++) {
		cout << v.get(i) << "\t";
	}
	cout << endl;
}
int main() {
	vector<float> a;
	vector<floatd> b;
	a.set(0, 0);
	a.set(1, 1);
	a.set(2, 2);
	a.set(3, 3);
	a.set(10, 10);
	print(a);
	print(b);
	cout << endl;

	b = a;
	print(a);
	print(b);
	cout << endl;

	a.set(0, 2);
	print(a);
	print(b);
	cout << endl;

	a.set(30, 1);
	a.set(31, 31);
	a.set(32, 31);
	print(a);
	cout << endl;

	a.pushback(1);
	print(a);
	cout << endl;

	a.pushfront(3);
	print(a);
	cout << endl;

	return 0;
}
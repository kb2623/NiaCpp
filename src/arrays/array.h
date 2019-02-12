#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

#include <vector>
#include <random>

template<typename T = double>
class Array {
private:
	T* data;
	std::vector<unsigned int> shape;

	void copy(const Array<T> oo) {
		shape = oo.shape;
		auto size = oo.count();
		data = new T[size];
		for (int i = 0; i < size; i++) data[i] = oo[i];
	}

	void deleteThis() {
		delete [] data;
	}

public:
	Array() : data(nullptr) {}

	Array(std::vector<unsigned int> ishape) : shape(ishape) {
		if (shape.size() <= 0) return;
		auto rsize = count();
		data = new T[rsize];
	}

	Array(const Array<T> &a) {
		copy(a);
	}

	template<typename TO>
	Array<T> operator =(Array<TO> other) {
		deleteThis();
		const auto oo = other;
		return this;
	}

	unsigned int count() {
		unsigned int size = 1;
		for (auto it = shape.rbegin(); it != shape.rend(); it++) size *= *it;
		if (shape[0] == 0) return 0;
		else return size;
	}

	T& operator [](unsigned int i) {
		return data[i];
	}

	template<typename... Is>
	Array<T> operator ()(Is... args) {
		const unsigned int size = sizeof...(args);
		unsigned int iis[size] = {args...};
		unsigned int ii = 0;
		for (int i = 0; i < size - 1; i++) {
			unsigned int tmp = 1;
			for (auto j = 0; j < shape.size() - i - 1; j++) {
				tmp *= shape[shape.size() - 1 - j];
			}
			ii += tmp * iis[i];
		}
		ii += iis[size - 1];
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator +(Array<TO> other) {
		// TODO brodcasting
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator +(TO other) {
		// TODO brodcasting
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator -(Array<TO> other) {
		// TODO brodcasting
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator -(TO other) {
		// TODO brodcasting
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator *(Array<TO> other) {
		// TODO brodcasting
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator *(TO other) {
		// TODO brodcasting
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator /(Array<TO> other) {
		// TODO brodcasting
		return Array<T>();
	}

	template<typename TO>
	Array<T> operator /(TO other) {
		// TODO brodcasting
		return Array<T>();
	}

	~Array() {
		deleteThis();
	}
};

#endif // ARRAY_H

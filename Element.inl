#include <iostream>

namespace Vectors {
	
	template<typename T>
	Element<T>::Element(T* data) : _data(data), _next(nullptr) {}

	template<typename T>
	Element<T>::Element(T* data, Element<T>* next) : _data(data), _next(next) {}

	template<typename T>
	Element<T>::Element(const Element<T>& other) : _next(nullptr) {
		
		_data = new T(*other._data);
	}

	template<typename T>
	Element<T>::~Element() {

		delete _data;
	}

	template<typename T>
	Element<T>& Element<T>::operator =(const Element<T>& other) {

		if (this == &other)
			return *this;

		_data = new T(*other._data);
		_next = nullptr;
		return *this;
	}

	template<typename T>
	bool Element<T>::operator ==(const Element<T>& other) {

		return _data == other._data &&
			_next == other._next;
	}

	template<typename T>
	T* Element<T>::data() const {

		return _data;
	}

	template<typename T>
	Element<T>* Element<T>::next() const {

		return _next;
	}

	template<typename T>
	void Element<T>::data(T* data) {

		_data = data;
	}

	template<typename T>
	void Element<T>::next(Element<T>* next) {

		_next = next;
	}
}
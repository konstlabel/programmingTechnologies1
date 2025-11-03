#pragma once

#include <iostream>
#include <type_traits>
#include <stdexcept>

namespace Vectors {
	template<typename T>
	Vector<T>::Vector() : _size(0), _head(nullptr), _tail(nullptr)  {

		std::cout << "The Vector's default constructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>::Vector(Element<T>* head) : _size(1), _head(head), _tail(head) {

		while (_tail->_next != nullptr) {
			_tail = _tail->_next;
			_size++;
		}

		std::cout << "The Vector's parameterized constructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>::Vector(const Vector<T>& other) {

		if (!other.isEmpty()) {
			Element<T>* current = other._head;
			while (current != nullptr) {
				add(current->_data);
				current = current->_next;
			}
		}
		else {
			_size = 0;
			_head = nullptr;
			_tail = nullptr;
		}
		std::cout << "The Vector's copy constructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>::~Vector() {

		clear();

		std::cout << "The Vector's destructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator =(const Vector<T>& other) {

		if (this == &other)
			return *this;

		clear();

		if (other.isEmpty())
			return *this;

		Element<T>* current = other._head;
		while (current != nullptr) {
			add(current->_data);
			current = current->_next;
		}

		return *this;
	}

	template<typename T>
	bool Vector<T>::operator ==(const Vector<T>& other) const {

		if (_size != other._size || _head != other._head || _tail != other._tail) 
			return false;

		return true;
	}

	template<typename T>
	int Vector<T>::size() const {

		return _size;
	}

	template<typename T>
	T* Vector<T>::head() const {

		return _head->_data;
	}

	template<typename T>
	T* Vector<T>::tail() const {

		return _tail->_data;
	}

	template<typename T>
	bool Vector<T>::add(const T* obj) {

		if (obj == nullptr)
			throw std::invalid_argument("Cannot add null object");

		Element<T>* ne = new Element<T>(new T(*obj));
		if (_head == nullptr)
			_head = _tail = ne;
		else {
			_tail->_next = ne;
			_tail = ne;
		}

		_size++;
		return true;
	}

	template<typename T>
	bool Vector<T>::set(int index, const T* obj) {
		if (index < 0 || index >= _size)
			throw std::out_of_range("Index out of range");

		if (obj == nullptr)
			throw std::invalid_argument("Cannot set null object");

		Element<T>* ne = new Element<T>(*obj);

		Element<T>* element = _head;
		if (index == 0) {
			ne->_next = _head->_next;
			_head = ne;
			delete element;
		}
		else {
			for (int i = 1; i < index; i++)
				element = element->_next;
			Element<T>* temp = element->_next;
			element->_next = ne;
			ne->_next = temp->_next;
			delete temp;
		}

		if (ne->_next == nullptr)
			_tail = ne;

		return true;
}

	template<typename T>
	bool Vector<T>::remove(int index) {

		if (index < 0 || index >= _size)
			throw std::out_of_range("Index out of range");

		Element<T>* element = _head;
		if (index == 0) {
			_head = _head->_next;
			delete element;
		}
		else {
			for (int i = 1; i < index; i++)
				element = element->_next;
			Element<T>* temp = element->_next;
			element->_next = temp->_next;
			delete temp;
		}

		if (element->_next == nullptr)
			_tail = element;

		_size--;
		return true;
	}

	template<typename T>
	bool Vector<T>::removeObject(T* obj) {

		if (obj == nullptr)
			throw std::invalid_argument("Cannot delete null object");

		int index = indexOf(obj);
		if (index == -1)
			throw std::invalid_argument("Object not found in vector");

		return remove(index);
	}

	template<typename T>
	bool Vector<T>::clear() {

		while (_head != nullptr) {
			Element<T>* temp = _head->next();
			delete _head;
			_head = temp;
		}
		_tail = nullptr;
		_size = 0;
		return true;
	}

	template<typename T>
	T* Vector<T>::get(int index) {

		if (index < 0 || index >= _size)
			throw std::out_of_range("Index out of range");

		Element<T>* element = _head;
		for (int i = 0; i < index; i++)
			element = element->_next;
		return element->_data;
	}


	template<typename T>
	int Vector<T>::indexOf(T* obj) const {

		Element<T>* element = _head;
		for (int i = 0; i < _size; i++) {
			if (element->_data != nullptr && *element->_data == *obj) {
				return i;
			}
			element = element->next();
		}

		return -1;
	}

	template<typename T>
	bool Vector<T>::contains(T* obj) const {

		return indexOf(obj) >= 0;
	}

	template<typename T>
	bool Vector<T>::isEmpty() const {

		return _size == 0;
	}

	template<typename T>
	typename Vector<T>::Iterator Vector<T>::begin() {
		
		return Iterator(_head);
	}

	template<typename T>
	typename Vector<T>::Iterator Vector<T>::end() {
		
		return Iterator(nullptr);
	}

	template<typename T>
	typename Vector<T>::Iterator Vector<T>::begin() const {

		return Iterator(_head);
	}

	template<typename T>
	typename Vector<T>::Iterator Vector<T>::end() const {

		return Iterator(nullptr);
	}

	template<typename T>
	Vector<T>::Iterator::Iterator(Element<T>* ptr) : ptr(ptr) {}

	template<typename T>
	T* Vector<T>::Iterator::operator*() {
		
		return ptr->_data;
	}

	template<typename T>
	typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
		
		ptr = ptr->_next;
		return *this;
	}

	template<typename T>
	bool Vector<T>::Iterator::operator !=(const Iterator& other) const {
		
		return ptr != other.ptr;
	}

	template<typename T>
	bool Vector<T>::Iterator::operator ==(const Iterator& other) const {
		return ptr == other.ptr;
	}
}
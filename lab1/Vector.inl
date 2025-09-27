#pragma once

#include <iostream>
#include <type_traits>
#include <stdexcept>

namespace Vectors {

	template<typename T>
	void Vector<T>::resize() {

		capacity = capacity * 2;
		T** newData = new T*[capacity];

		for (int i = 0; i < size; i++) {
			if (ownsObjects == true)
				newData[i] = new T(*data[i]);
			else
				newData[i] = data[i];
		}

		for (int i = size; i < capacity; i++)
			newData[i] = nullptr;

		if (ownsObjects == true) {
			for (int i = 0; i < size; i++) {
				delete data[i];
			}
		}
		delete[] data;
		
		data = newData;
	}

	template<typename T>
	void Vector<T>::sort() {

		if constexpr (std::is_same_v<T, int>) {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (*data[j] > *data[j + 1]) {
						std::swap(data[j], data[j + 1]);
					}
				}
			}
		}

		else if constexpr (std::is_same_v<T, std::string>) {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (*data[j] > *data[j + 1]) {
						std::swap(data[j], data[j + 1]);
					}
				}
			}
		}

		else if constexpr (std::is_same_v <T, Persons::Person>) {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (data[j]->getSurname() > data[j + 1]->getSurname()) {
						std::swap(data[j], data[j + 1]);
					}
					else if (data[j]->getSurname() == data[j + 1]->getSurname()) {
						if (data[j]->getName() > data[j + 1]->getName()) {
							std::swap(data[j], data[j + 1]);
						}
						else if (data[j]->getName() == data[j + 1]->getName()) {
							if (data[j]->getPatronymic() > data[j + 1]->getPatronymic()) {
								std::swap(data[j], data[j + 1]);
							}
						}
					}
				}
			}
		}

		else if constexpr (std::is_same_v <T, Groups::Group>) {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (data[j]->getName() > data[j + 1]->getName()) {
						std::swap(data[j], data[j + 1]);
					}
				}
			}
		}

		else {
			throw std::logic_error("Sort not implemented for this type");
		}
	}

	template<typename T>
	Vector<T>::Vector() : size(0), capacity(8), ownsObjects(true) {

		data = new T* [capacity];
		for (int i = 0; i < capacity; ++i)
			data[i] = nullptr;
		std::cout << "The Vector's default constructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>::Vector(int capacity, bool ownsObjects) : size(0), capacity(capacity), ownsObjects(ownsObjects) {
		
		if (capacity <= 0) {
			throw std::invalid_argument("Capacity must be greater than 0");
		}

		data = new T* [capacity];
		for (int i = 0; i < capacity; ++i)
			data[i] = nullptr;
		std::cout << "The Vector's parameterized constructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>::Vector(const Vector<T>& other) : size(other.size), capacity(other.capacity), ownsObjects(other.ownsObjects) {
	
		data = new T* [capacity];
		for (int i = 0; i < size; i++) {
			if (ownsObjects) {
				data[i] = new T(*other.data[i]);
			}
			else {
				data[i] = other.data[i];
			}
		}

		std::cout << "The Vector's copy constructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>::~Vector() {

		if (ownsObjects) {
			for (int i = 0; i < size; i++) {
				delete data[i];
			}
		}
		delete[] data;
		
		std::cout << "The Vector's destructor is called " << std::endl;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator =(const Vector<T>& other) {

		if (this == &other) return *this;
		
		if (ownsObjects) {
			for (int i = 0; i < size; i++) {
				delete data[i];
			}
		}
		delete[] data;
		
		size = other.size;
		capacity = other.capacity;
		ownsObjects = other.ownsObjects;

		data = new T* [capacity];
		for (int i = 0; i < size; i++) {
			if (ownsObjects) {
				data[i] = new T(*other.data[i]);
			}
			else {
				data[i] = other.data[i];
			}
		}

		return *this;
	}

	template<typename T>
	bool Vector<T>::operator ==(const Vector<T>& other) const {
	
		if (size != other.size) return false;
		
		for (int i = 0; i < size; i++) {
			if (*data[i] != *other.data[i]) return false;
		}

		return true;
	}

	template<typename T>
	int Vector<T>::getSize() const {
	
		return size;
	}

	template<typename T>
	int Vector<T>::getCapacity() const {
	
		return capacity;
	}

	template<typename T>
	bool Vector<T>::getOwnsObjects() const {
	
		return ownsObjects;
	}

	template<typename T>
	void Vector<T>::add(const T* obj) {
	
		if (obj == nullptr)
			throw std::invalid_argument("Cannot add null object");

		if (size >= capacity)
			resize();

		if constexpr (std::is_same_v<T, std::string>) {

			std::string trimmed = *obj;
			trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
			trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

			if (trimmed.empty())
				throw std::invalid_argument("Error! Empty string is not allowed");

			data[size] = new T(trimmed);
		}

		else {
			
			if (ownsObjects) {
				data[size] = new T(*obj);
			}
			else {
				data[size] = const_cast<T*>(obj);
			}
		}

		size++;
		sort();
	}

	template<typename T>
	void Vector<T>::add(const T& obj) {
	
		T* copy = nullptr;

		try {
			copy = new T(obj);
			add(copy);
		}
		catch (const std::invalid_argument& e) {
			delete copy;
			throw e;
		}
	}

	template<typename T>
	void Vector<T>::add(std::unique_ptr<T> obj) {
	
		if (obj == nullptr)
			throw std::invalid_argument("Cannot add null object");

		if (size >= capacity)
			resize();
		
		if constexpr (std::is_same_v<T, std::string>) {
			
			std::string trimmed = *obj;
			trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
			trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

			if (trimmed.empty())
				throw std::invalid_argument("Error! Empty string is not allowed");
			
			data[size] = new T(trimmed);
		}
		
		else {
			
			if (ownsObjects) {
				data[size] = obj.release();
			}
			else {
				data[size] = new T(*obj);
			}
		}

		size++;
		sort();
	}

	template<typename T>
	void Vector<T>::deleteByIndex(int index) {
	
		if (index < 0 || index >= size)
			throw std::out_of_range("Index out of range");
		
		if (ownsObjects) {
			delete data[index];
		}
		for (int i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

	template<typename T>
	void Vector<T>::deleteByObject(T* obj) {
	
		if (obj == nullptr)
			throw std::invalid_argument("Cannot delete null object");

		int index = getIndexByPointer(obj);
		if (index == -1)
			throw std::invalid_argument("Object not found in vector");

		deleteByIndex(index);
	}

	template<typename T>
	void Vector<T>::deleteByObject(const T& obj) {
	
		for (int i = 0; i < size; i++) {
			if (data[i] && *data[i] == obj) {
				if (ownsObjects)
					delete data[i];
				for (int j = i; j < size - 1; j++)
					data[j] = data[j + 1];

				size--;
				return;
			}
		}
		throw std::invalid_argument("Object not found");
	}

	template<typename T>
	void Vector<T>::print() const {
	
		if (size == 0) {
			std::cout << "Vector is empty" << std::endl;
			return;
		}

		for (int i = 0; i < size; i++) {
			if constexpr (std::is_same_v<T, int> || std::is_same_v<T, std::string>) {
				std::cout << "\t" << i+1 << ". " << *data[i] << std::endl;
			}
			else {
				std::cout << "\t" << i+1 << ". " << data[i]->toString() << std::endl;
			}
		}
	}

	template<typename T>
	T* Vector<T>::getByIndex(int index) {
	
		if (index < 0 || index >= size)
			throw std::out_of_range("Index out of range");
	
		return data[index];
	}

	template<typename T>
	int Vector<T>::getByIndex(int index) const {
	
		if constexpr (!std::is_same_v<T, int>)
			throw std::logic_error("getByIndex is only implemented for int type");

		if (index < 0 || index >= size)
			throw std::out_of_range("Index out of range");
	
		return *data[index];
	}

	template<typename T>
	int Vector<T>::getIndexByPointer(T* obj) const {
	
		if (obj == nullptr)
			throw std::invalid_argument("Cannot search for null object");
		
		for (int i = 0; i < size; i++) {
			if (data[i] == obj) {
				return i;
			}
	
		}
		return -1;
	}

	template<typename T>
	int Vector<T>::getIndexByObject(const T& obj) const {
	
		for (int i = 0; i < size; i++) {
			if (*data[i] == obj) {
				return i;
			}
		}
	
		return -1;
	}

	template<typename T>
	bool Vector<T>::exists(const T& obj) const {

		return getIndexByObject(obj) != -1;
	}

	template<typename T>
	bool Vector<T>::isEmpty() const {
	
		return size == 0;
	}
}
#pragma once

#include <iostream>
#include <type_traits>
#include <stdexcept>

namespace Vectors {

    template<typename T>
    void Vector<T>::resize() {

        capacity = capacity * 2;
        T** newData = new T * [capacity];

        
        for (int i = 0; i < size; i++)
            if constexpr (std::is_same_v<T, std::string>) {
                newData[i] = new T(*data[i]);
            }
            else {
                if (ownsObjects == true)
                    newData[i] = new T(*data[i]);
                else
                    newData[i] = data[i];
            }

        delete[] data;
        data = newData;
    }

    template<typename T>
    void Vector<T>::sort() {

        if constexpr (std::is_same_v<T, std::string>) {

            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {

                    if (*data[j] > *data[j + 1]) {
                        T* temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                }
            }
        }
        else if constexpr (std::is_same_v<T, Groups::Group>) {

            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {

                    if (data[j]->getName() > data[j + 1]->getName()) {
                        T* temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                }
            }
        }
        else {

            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {

                    if (data[j]->getSurname() > data[j + 1]->getSurname()) {
                        T* temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }

                    else if (data[j]->getSurname() == data[j + 1]->getSurname()) {
                        if (data[j]->getName() > data[j + 1]->getName()) {
                            T* temp = data[j];
                            data[j] = data[j + 1];
                            data[j + 1] = temp;
                        }
                    }
                }
            }
        }
        
    }

    template<typename T>
    Vector<T>::Vector() : size(0), capacity(16), ownsObjects(true) {

        data = new T* [capacity];

        std::cout << "The Vector's default constructor is called " << std::endl;
    }

    template<typename T>
    Vector<T>::Vector(int initialCapacity, bool ownsObjects)
        : size(0), capacity(initialCapacity), ownsObjects(ownsObjects) {
        
        data = new T* [capacity];

        std::cout << "The Vector's parameterized constructor is called " << std::endl;
    }

    template<typename T>
    Vector<T>::Vector(const Vector<T>& other)
        : size(other.size), capacity(other.capacity), ownsObjects(other.ownsObjects) {

        data = new T* [capacity];

        for (int i = 0; i < size; i++) {
            if (ownsObjects)
                data[i] = new T(*other.data[i]);
            else
                data[i] = other.data[i];
        }

        std::cout << "The Vector's copy constructor is called " << std::endl;
    }

    template<typename T>
    Vector<T>::~Vector() {

        if (ownsObjects) {
            for (int i = 0; i < size; i++)
                delete data[i];
        }
        delete[] data;

        std::cout << "The Vector's destructor is called" << std::endl;
    }

    template<typename T>
    Vector<T>& Vector<T>::operator =(const Vector<T>& other) {

        if (this == &other) return *this;

        if (data != nullptr) {
            if (ownsObjects) {
                for (int i = 0; i < size; i++)
                    delete data[i];
            }
            delete[] data;
        }

        size = other.size;
        capacity = other.capacity;
        ownsObjects = other.ownsObjects;
        data = new T * [capacity];

        for (int i = 0; i < size; i++) {
            if (ownsObjects)
                data[i] = new T(*other.data[i]);
            else
                data[i] = other.data[i];
        }

        return *this;
    }

    template<typename T>
    bool Vector<T>::operator ==(const Vector<T>& other) const {
        
        return (data == other.data) &&
            (size == other.size) &&
            (capacity == other.capacity) &&
            (ownsObjects == other.ownsObjects);
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
    void Vector<T>::add(const T* newElement) {

        if (newElement == nullptr)
            throw std::invalid_argument("Error! Null pointer element is not allowed");

        if constexpr (std::is_same_v<T, std::string>) {

            std::string trimmed = *newElement;
            trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
            trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);


            if (trimmed.empty())
                throw std::invalid_argument("Error! Empty string is not allowed");
        }

            if (size >= capacity) resize();

            if (ownsObjects)
                data[size++] = new T(*newElement);
            else
                data[size++] = const_cast<T*>(newElement);

            sort();
    }

    template<typename T>
    void Vector<T>::deleteByIndex(int index) {

        if (index < 0 || index >= size)
            throw std::out_of_range("Error! index must greater than 0 and less than or equal to current size (" + std::to_string(size) + ")");

        if (ownsObjects)
            delete data[index];

        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];

        data[size - 1] = nullptr;
        size--;
    }

    template<typename T>
    void Vector<T>::deleteByObject(T* obj) {

        for (int i = 0; i < size; i++) {
            if (data[i] == obj) {
                if (ownsObjects)
                    delete data[i];

                for (int j = i; j < size; j++)
                    data[j] = data[j + 1];

                data[size - 1] = nullptr;
                size--;
                
                break;
            }

            if (i == size - 1) {
                throw std::invalid_argument("Error! No object in data");
            }
        }
    }

    template<typename T>
    void Vector<T>::print() const {

        if (size == 0) {
            std::cout << "Vector is empty" << std::endl;
            return;
        }

        if constexpr (std::is_same_v<T, std::string>) {
            for (int i = 0; i < size; i++) {
                std::cout << "\t" << i + 1 << ". " << *data[i] << std::endl;
            }
        }
        else {

            for (int i = 0; i < size; i++) {
                std::cout << "\t" << i + 1 << ". " << data[i]->toString() << std::endl;
            }
        }
    }

    template<typename T>
    T* Vector<T>::getByIndex(int index) {

        if (index < 0 || index >= size)
            throw std::out_of_range("Error! index must greater than 0 and less than or equal to current size (" + std::to_string(size) + ")");

        return data[index];
    }

    template<typename T>
    int Vector<T>::getIndex(T* obj) const {

        for (int i = 0; i < size; i++) {
            if (data[i] == obj) 
                return i;
        }
        return -1;
    }

    template<typename T>
    bool Vector<T>::exists(const T& obj) const {

        for (int i = 0; i < size; i++) {
            if (data[i] == &obj) return true;
        }
        return false;
    }

    template<typename T>
    bool Vector<T>::isEmpty() const {
        return size == 0;
    }
}
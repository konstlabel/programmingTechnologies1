#include <iostream>

namespace Vectors {

    template<typename T>
    void Vector<T>::resize() {

        capacity = capacity * 2;
        T** newData = new T * [capacity];

        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    template<typename T>
    void Vector<T>::sort() {

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

    template<typename T>
    Vector<T>::Vector() : size(0), capacity(16), ownsObjects(true) {

        data = new T * [capacity];

        std::cout << "The Vector's default constructor is called " << std::endl;
    }

    template<typename T>
    Vector<T>::Vector(int initialCapacity, bool ownsObjects)
        : size(0), capacity(initialCapacity), ownsObjects(ownsObjects) {
        
        data = new T * [capacity];

        std::cout << "The Vector's parameterized constructor is called " << std::endl;
    }

    template<typename T>
    Vector<T>::Vector(const Vector<T>& other)
        : size(other.size), capacity(other.capacity), ownsObjects(other.ownsObjects) {

        data = new T * [capacity];

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

        if (size >= capacity) resize();

        if (ownsObjects)
            data[size++] = new T(*newElement);
        else
            data[size++] = const_cast<T*>(newElement);

        this->sort();
    }

    template<typename T>
    void Vector<T>::print() const {

        for (int i = 0; i < size; i++) {
            std::cout << "\t" << i + 1 << ". " << data[i]->toString() << std::endl;
        }
    }

    template<typename T>
    void Vector<T>::deleteByIndex(int index) {

        if (index < 0 || index >= size) return;

        if (ownsObjects)
            delete data[index];

        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];

        size--;
    }

    template<typename T>
    T* Vector<T>::getByIndex(int index) {
        if (index < 0 || index >= size) return;

        return data[index];
    }

    template<typename T>
    bool Vector<T>::exists(const T& obj) {
        for (int i = 0; i < size; i++) {
            if (this->getByIndex(i) == obj) return true;
        }
        return false;
    }
}
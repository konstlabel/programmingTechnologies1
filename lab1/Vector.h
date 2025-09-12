#pragma once

#include <string>

namespace Vectors {

    template<typename T>
    class Vector {
        T** data;
        int size;
        int capacity;
        bool ownsObjects;

        void resize();
        void sort();

    public:
        Vector();
        explicit Vector(int data, bool ownsObjects);
        Vector(const Vector<T>& other);

        ~Vector();

        Vector& operator =(const Vector& other);
        bool operator ==(const Vector& other) const;

        int getSize() const;
        int getCapacity() const;
        bool getOwnsObjects() const;

        void add(const T* obj);
        void deleteByIndex(int index);
        void deleteByObject(T* obj);
        void print() const;

        T* getByIndex(int index);
        int getIndex(T* obj) const;
        bool exists(const T& obj) const;
        bool isEmpty() const;
    };
}

#include "Vector.inl"
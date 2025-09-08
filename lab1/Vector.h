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

        int getSize() const;
        int getCapacity() const;
        bool getOwnsObjects() const;

        void add(const T* obj);
        void print() const;
        void deleteByIndex(int index);

        T* getByIndex(int index);
        bool exists(const T& obj);
    };
}

#include "Vector.inl"
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
        explicit Vector(int, bool);
        Vector(const Vector<T>&);

        ~Vector();

        Vector& operator =(const Vector&);

        int getSize() const;
        int getCapacity() const;
        bool getOwnsObjects() const;

        void add(const T*);
        void print() const;
        void deleteByIndex(int);

        T* getByIndex(int);
    };
}

#include "Vector.inl"
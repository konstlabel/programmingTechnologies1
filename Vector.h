#pragma once
#include <string>
#include <memory>

#include "Element.h"

namespace Vectors {
    template<typename T>
    class Vector {

        Element<T>* _head;
        Element<T>* _tail;
        int _size;

    public:
        Vector();
        explicit Vector(Element<T>* head);
        Vector(const Vector<T>& other);

        ~Vector();

        Vector& operator =(const Vector& other);
        bool operator ==(const Vector& other) const;

        int size() const;
        T* head() const;
        T* tail() const;

        bool add(const T* obj);
        bool set(int index, const T* obj);
        bool remove(int index);
        bool removeObject(T* obj);
        bool clear();

        T* get(int index);
        int indexOf(T* obj) const;

        bool contains(T* obj) const;
        bool isEmpty() const;

        class Iterator {
            Element<T>* ptr;
        public:
            Iterator(Element<T>* ptr);

            T* operator*();
            Iterator& operator++();
            bool operator !=(const Iterator& other) const;
            bool operator==(const Iterator& other) const;
        };

		Iterator begin();
		Iterator end();
        Iterator begin() const;
        Iterator end() const;

    };
}

#include "Vector.inl"

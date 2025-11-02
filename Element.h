#pragma once

namespace Vectors {
	template<typename T>
	class Element {
		T* _data;
		Element* _next;

		Element(T* data);
		Element(T* data, Element<T>* next);
		Element(const Element<T>& other);

		~Element();

		Element<T>& operator =(const Element<T>& other);
		bool operator ==(const Element<T>&other);
		T* data() const;
		Element* next() const;

		void data(T* data);
		void next(Element<T>* next);
	public:
		template<typename>
		friend class Vector;
	};
}

#include "Element.inl"
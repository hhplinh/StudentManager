#pragma once

#include "Node.hpp"

template <class T>
class Iterator
{
protected:
	Node<T> *pointer_;

public:
	Iterator();
	Iterator(Node<T>*);
	Iterator(const Iterator<T>&);

	Iterator<T>& operator=(const Iterator<T>&);
	bool operator==(const Iterator<T>&) const;
	bool operator!=(const Iterator<T>&) const;
	int operator-(const Iterator<T>&) const;

	T& operator*() const;
	T* operator->() const;
	Node<T>* getPointer() const;
	
	virtual Iterator<T>& operator++();
	Iterator<T> operator++(int);
	Iterator<T> operator+(int) const;
	Iterator<T>& operator+=(int);

	virtual Iterator<T>& operator--();
	Iterator<T> operator--(int);
	Iterator<T> operator-(int) const;
	Iterator<T>& operator-=(int);
};

#include "Iterator.tpp"

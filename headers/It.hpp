#pragma once

template <class T>
class It
{
public:
	It();
	It(Node<T>*);
	It(const It<T>&);

	It<T>& operator=(const It<T>&);
	bool operator==(const It<T>&) const;
	bool operator!=(const It<T>&) const;
	int operator-(const It<T>&) const;

	T& operator*();
	const T& operator*() const;
	T* operator->();
	const T* operator->() const;
	Node<T>* getPointer();
	const Node<T>* getPointer() const;
	
	virtual It<T>& operator++();
	It<T> operator++(int);
	It<T> operator+(int) const;
	It<T>& operator+=(int);

	virtual It<T>& operator--();
	It<T> operator--(int);
	It<T> operator-(int) const;
	It<T>& operator-=(int);

protected:
	Node<T> *pointer_;

	virtual It<T>& increase();
	virtual It<T>& decrease();
};

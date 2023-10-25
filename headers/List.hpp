#pragma once

#include <initializer_list>

#include "Node.hpp"
#include "Iterator.hpp"

template <class T>
class List
{
private:
	Node<T> *head_, *tail_;
	int size_;

	template <class Compare>
	void sortRange(Iterator<T>, Iterator<T>, Compare);
	template <class Compare>
	void mergeRange(Iterator<T>, Iterator<T>, Iterator<T>, Compare);

public:
	typedef Iterator<T> iterator;

	/* Constructors */
	List();
	List(const List<T>&);
	List(std::initializer_list<T>);

	/* Destructor */
	~List();

	List<T>& operator=(const List<T>&);

	/* Element access */
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	/* Iterators */
	iterator begin() const;
	iterator end() const;

	/* Capacity */
	bool empty() const;
	int size() const;

	/* Modifiers */
	void clear();
	
	iterator insert(iterator pos, const T &value); // Inserts value before pos. Returns iterator pointing to value.
	iterator insert(iterator pos, std::initializer_list<T> Ilist); // Inserts everything from Ilist. Returns iterator pointing to the first element inserted.
	
	iterator erase(iterator pos); // Removes element at pos. Returns iterator following the last removed element.
	iterator erase(iterator first, iterator last); // Removes element in range [first, last).
	
	void push_back(const T&);
	void pop_back();
	void push_front(const T&);
	void pop_front();

	void swap(List<T>&); // Swap the contents of two Lists.

	/* Operations */
	void merge(const List<T>&); // Merge two sorted Lists.
	template <class Compare>
	void merge(const List<T>&, Compare);
	void reverse();

	iterator find(const T &value) const;
	template <class UnaryPredicate>
	iterator find_if(UnaryPredicate predicate) const;
	
	int remove(const T &value); // Removes all elements equal to value. Returns the number of elements removed.
	template <class UnaryPredicate>
	int remove_if(UnaryPredicate p); // Removes all elements of which predicate p is equal to value. Returns the number of elements removed.

	int unique(); // For each group of equal adjacent elements, keep only the first element. Returns the number of elements removed.
	template <class BinaryPredicate>
	int unique(BinaryPredicate);

	void sort();
	template <class Compare>
	void sort(Compare);
};

#include "List.tpp"

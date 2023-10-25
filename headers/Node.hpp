#pragma once

template <class T>
struct Node
{
	T value;
	Node<T> *prev, *next;

	Node();
	Node(const T &value_, Node<T> *prev_ = nullptr, Node<T> *next_ = nullptr);
};

#include "Node.tpp"

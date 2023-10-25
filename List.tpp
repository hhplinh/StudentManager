#include <iostream>
#include <algorithm>

template <class T>
List<T>::List()
	: head_(new Node<T>), tail_(new Node<T>), size_(0)
{
	head_->prev = nullptr;
	head_->next = tail_;
	tail_->prev = head_;
	tail_->next = nullptr;
}

template <class T>
List<T>::List(const List<T> &Other)
	: List()
{
	*this = Other;
}

template <class T>
List<T>::List(std::initializer_list<T> Ilist)
	: List()
{
	insert(begin(), Ilist);
}

template <class T>
List<T>::~List()
{
	clear();
	delete head_;
	delete tail_;
}

template <class T>
List<T>& List<T>::operator=(const List<T> &Other)
{
	for (auto it = Other.begin(); it != Other.end(); ++it)
	{
		push_back(*it);
	}
	return *this;
}

template <class T>
T& List<T>::front()
{
	return *begin();
}

template <class T>
const T& List<T>::front() const
{
	return *begin();
}

template <class T>
T& List<T>::back()
{
	return *(end()-1);
}

template <class T>
const T& List<T>::back() const
{
	return *(end()-1);
}

template <class T>
typename List<T>::iterator List<T>::begin() const
{
	return List<T>::iterator(head_->next);
}

template <class T>
typename List<T>::iterator List<T>::end() const
{
	return List<T>::iterator(tail_);
}

template <class T>
bool List<T>::empty() const
{
	return begin() == end();
}

template <class T>
int List<T>::size() const
{
	return size_;
}

template <class T>
void List<T>::clear()
{
	erase(begin(), end());
}

template <class T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, const T &value)
{
	size_++;
	
	Node<T> *curr = pos.getPointer();
	Node<T> *newNode = new Node<T>(value, curr->prev, curr);
	curr->prev->next = newNode;
	curr->prev = newNode;
	return pos-1;
}

template <class T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, std::initializer_list<T> Ilist)
{
	auto returnIt = pos-1;
	for (auto element: Ilist)
	{
		insert(pos, element);
	}
	return returnIt++;
}

template <class T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator pos)
{
	size_--;
	
	Node<T> *curr = pos.getPointer();
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	auto tmp = pos+1;
	delete curr;
	return tmp;
}

template <class T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator first, typename List<T>::iterator last)
{
	auto it = first;
	for (; it != last; it = erase(it));
	return it;
}

template <class T>
void List<T>::push_back(const T &value)
{
	insert(end(), value);
}

template <class T>
void List<T>::pop_back()
{
	erase(end()-1);
}

template <class T>
void List<T>::push_front(const T &value)
{
	insert(begin(), value);
}

template <class T>
void List<T>::pop_front()
{
	erase(begin());
}

template <class T>
void List<T>::swap(List<T> &Other)
{
	std::swap(head_, Other.head_);
	std::swap(tail_, Other.tail_);
}

template <class T>
void List<T>::merge(const List<T> &Other)
{
	merge(Other,
		  [](const T &a, const T &b) -> bool
		  {
			  return a < b;
		  });
}

template <class T>
template <class Compare>
void List<T>::merge(const List<T> &Other, Compare cmp)
{
	auto it = begin();
	auto otherIt = Other.begin();
	while (it != end() && otherIt != Other.end())
	{
		for (; it != end() && !cmp(*otherIt, *it); ++it);
		insert(it, *otherIt);
		++otherIt;
	}
	while (it == end() && otherIt != Other.end())
	{
		insert(it, *otherIt);
		++otherIt;
	}
}

template <class T>
void List<T>::reverse()
{
	for (Node<T> *curr = head_; curr; curr = curr->prev)
	{
		std::swap(curr->prev, curr->next);
	}
	std::swap(head_, tail_);
}

template <class T>
typename List<T>::iterator List<T>::find(const T &value) const
{
	return find_if(
		[&](const T &element) -> bool
		{
			return element == value;
		});
}

template <class T>
template <class UnaryPredicate>
typename List<T>::iterator List<T>::find_if(UnaryPredicate predicate) const
{
	for (auto it = begin(); it != end(); ++it)
	{
		if (predicate(*it))
		{
			return it;
		}
	}
	return end();
}

template <class T>
int List<T>::remove(const T &value)
{
	return remove_if(
		[&](const T &element) -> bool
		{
			return element == value;
		});
}

template <class T>
template <class UnaryPredicate>
int List<T>::remove_if(UnaryPredicate predicate)
{
	auto it = begin();
	int res = 0;
	while (it != end())
	{
		if (!predicate(*it))
		{
			++it;
			continue;
		}
		
		++res;
		it = erase(it);
	}
	return res;
}

template <class T>
int List<T>::unique()
{
	return unique(
		[](const T &a, const T &b) -> bool
		{
			return a == b;
		});
}

template <class T>
template <class BinaryPredicate>
int List<T>::unique(BinaryPredicate predicate)
{
	int res = 0;
	auto it = begin();
	while (it != end() && it+1 != end())
    {
		while (it+1 != end() && predicate(*it, *(it+1)))
		{
			++res;
			erase(it+1);
		}
		++it;
	}
	return res;
}

template <class T>
template <class Compare>
void List<T>::sortRange(typename List<T>::iterator first, typename List<T>::iterator last, Compare cmp)
{
	int dist = last-first;
	
	if (dist == 0 || dist == 1)
	{
		return;
	}
	
	sortRange(first, first + dist/2, cmp);
	sortRange(first + dist/2, last, cmp);
	mergeRange(first, first + dist/2, last, cmp);
}

template <class T>
template <class Compare>
void List<T>::mergeRange(typename List<T>::iterator first, typename List<T>::iterator mid, typename List<T>::iterator last, Compare cmp)
{
	List<T> Left, Right;
	for (auto it = first; it != mid; ++it)
	{
		Left.push_back(*it);
	}
	for (auto it = mid; it != last; ++it)
	{
		Right.push_back(*it);
	}
	Left.merge(Right, cmp);
	auto it = first;
	auto leftIt = Left.begin();
	while (it != last)
	{
		*it = *leftIt;
		++it;
		++leftIt;
	}
}

template <class T>
void List<T>::sort()
{
	sort(
		[](const T &a, const T &b) -> bool
		{
			return a < b;
		});
}

template <class T>
template <class Compare>
void List<T>::sort(Compare cmp)
{
	sortRange(begin(), end(), cmp);
}

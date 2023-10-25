template <class T>
Iterator<T>::Iterator()
	: pointer_(nullptr)
{}

template <class T>
Iterator<T>::Iterator(Node<T> *nPointer)
{
	pointer_ = nPointer;
}

template <class T>
Iterator<T>::Iterator(const Iterator<T> &other)
{
	*this = other;
}

template <class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T> &other)
{
	pointer_ = other.pointer_;
	return *this;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T> &other) const
{
	return pointer_ == other.pointer_;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const
{
	return !(*this == other);
}

template <class T>
int Iterator<T>::operator-(const Iterator<T> &other) const
{
	int res = 0;
	for (auto it = other; it != *this; ++it)
	{
		++res;
	}
	return res;
}

template <class T>
T& Iterator<T>::operator*() const
{
	return pointer_->value;
}

template <class T>
T* Iterator<T>::operator->() const
{
	return &pointer_->value;
}

template <class T>
Node<T>* Iterator<T>::getPointer() const
{
	return pointer_;
}

template <class T>
Iterator<T>& Iterator<T>::operator++()
{
	pointer_ = pointer_->next;
	return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator<T> res = *this;
	++(*this);
	return res;
}

template <class T>
Iterator<T> Iterator<T>::operator+(int steps) const
{
	Iterator<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		++res;
	}
	return res;
}

template <class T>
Iterator<T>& Iterator<T>::operator+=(int steps)
{
	return *this = *this + steps;
}

template <class T>
Iterator<T>& Iterator<T>::operator--()
{
	pointer_ = pointer_->prev;
	return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator--(int)
{
	Iterator<T> res = *this;
	--(*this);
	return res;
}

template <class T>
Iterator<T> Iterator<T>::operator-(int steps) const
{
	Iterator<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		--res;
	}
	return res;
}

template <class T>
Iterator<T>& Iterator<T>::operator-=(int steps)
{
	return *this = *this - steps;
}

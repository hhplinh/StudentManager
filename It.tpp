template <class T>
It<T>::It()
	: pointer_(nullptr)
{}

template <class T>
It<T>::It(Node<T> *nPointer)
{
	pointer_ = nPointer;
}

template <class T>
It<T>::It(const It<T> &other)
{
	*this = other;
}

template <class T>
It<T>& It<T>::operator=(const It<T> &other)
{
	pointer_ = other.pointer_;
	return *this;
}

template <class T>
bool It<T>::operator==(const It<T> &other) const
{
	return pointer_ == other.pointer_;
}

template <class T>
bool It<T>::operator!=(const It<T> &other) const
{
	return !(*this == other);
}

template <class T>
int It<T>::operator-(const It<T> &other) const
{
	int res = 0;
	for (auto it = other; it != *this; ++it)
	{
		++res;
	}
	return res;
}

template <class T>
T& It<T>::operator*()
{
	return pointer_->value;
}

template <class T>
const T& It<T>::operator*() const
{
	return pointer_->value;
}

template <class T>
T* It<T>::operator->()
{
	return &pointer_->value;
}

template <class T>
const T* It<T>::operator->() const
{
	return &pointer_->value;
}

template <class T>
Node<T>* It<T>::getPointer()
{
	return pointer_;
}

template <class T>
const Node<T>* It<T>::getPointer() const
{
	return pointer_;
}

template <class T>
It<T>& It<T>::operator++()
{
	return increase();
}

template <class T>
It<T> It<T>::operator++(int)
{
	It<T> res = *this;
	++(*this);
	return res;
}

template <class T>
It<T> It<T>::operator+(int steps) const
{
	It<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		++res;
	}
	return res;
}

template <class T>
It<T>& It<T>::operator+=(int steps)
{
	return *this = *this + steps;
}

template <class T>
It<T>& It<T>::operator--()
{
	return decrease();
}

template <class T>
It<T> It<T>::operator--(int)
{
	It<T> res = *this;
	--(*this);
	return res;
}

template <class T>
It<T> It<T>::operator-(int steps) const
{
	It<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		--res;
	}
	return res;
}

template <class T>
It<T>& It<T>::operator-=(int steps)
{
	return *this = *this - steps;
}

template <class T>
It<T>& It<T>::increase()
{
	return *this;
}

template <class T>
It<T>& It<T>::decrease()
{
	return *this;
}

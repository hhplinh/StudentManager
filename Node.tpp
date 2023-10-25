template <class T>
Node<T>::Node()
	: prev(nullptr), next(nullptr)
{}

template <class T>
Node<T>::Node(const T &value_, Node<T> *prev_, Node<T> *next_)
	: value(value_), prev(prev_), next(next_)
{}

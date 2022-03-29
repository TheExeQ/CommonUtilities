#pragma once

template <class T>
class Queue
{
public:
	Queue();

	int GetSize() const;

	const T& GetFront() const;
	T& GetFront();

	void Enqueue(const T& aValue);
	T Dequeue();
};

template <class T>
T Queue<T>::Dequeue()
{

}

template <class T>
void Queue<T>::Enqueue(const T& aValue)
{

}

template <class T>
T& Queue<T>::GetFront()
{

}

template <class T>
const T& Queue<T>::GetFront() const
{

}

template <class T>
int Queue<T>::GetSize() const
{

}

template <class T>
Queue<T>::Queue()
{

}

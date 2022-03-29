#pragma once

template <class T>
class Stack
{
public:
	Stack();

	int GetSize() const;

	const T& GetTop() const;
	T& GetTop();

	void Push(const T& aValue);
	T Pop();

private:
	std::vector<T> myStack;
};

template <class T>
T Stack<T>::Pop()
{

}

template <class T>
void Stack<T>::Push(const T& aValue)
{

}

template <class T>
T& Stack<T>::GetTop()
{

}

template <class T>
const T& Stack<T>::GetTop() const
{

}

template <class T>
int Stack<T>::GetSize() const
{

}

template <class T>
Stack<T>::Stack()
{

}

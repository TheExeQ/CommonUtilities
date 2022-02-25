#pragma once
#include <vector>
#include <cassert>

namespace CommonUtilities
{
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
	private:
		std::vector<T> myQueue;
		int myFirst;
		int myLast;
	};

	template <class T>
	T Queue<T>::Dequeue()
	{
		assert(myFirst <= myLast && "Last is bigger or equal to first");
		myFirst++;
		if (!myQueue.size()) return 0;
		return myQueue[myFirst - 1];
	}

	template <class T>
	void Queue<T>::Enqueue(const T& aValue)
	{
		myQueue.emplace_back(aValue);
		myLast++;
	}

	template <class T>
	T& Queue<T>::GetFront()
	{
		assert(myLast - myFirst > 0 && "Queue size is empty");
		return myQueue[myFirst];
	}

	template <class T>
	const T& Queue<T>::GetFront() const
	{
		assert(myLast - myFirst > 0 && "Queue size is empty");
		return myQueue[myFirst];
	}

	template <class T>
	int Queue<T>::GetSize() const
	{
		return myLast - myFirst;
	}

	template <class T>
	Queue<T>::Queue()
	{
		myFirst = 0;
		myLast = 0;
	}
}
